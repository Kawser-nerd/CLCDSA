package com.company;

import CSharpParser.CSharpLexer;
import CSharpParser.CSharpParser;
import JavaParser.JavaLexer;
import JavaParser.JavaParser;
import PythonParser.PythonLexer;
import PythonParser.PythonParser;
import com.opencsv.CSVReader;
import com.opencsv.CSVWriter;
import com.opencsv.exceptions.CsvValidationException;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CharStreams;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.ParseTree;
import org.antlr.v4.runtime.tree.ParseTreeWalker;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class GPTFeatureCollection {
    //static String content_dir = "./GPTCodeClones";
    static String content_dir = "./Source Codes/XLCost";

    public static void main(String[] args){
        List<Path> filesList = getAllFiles(content_dir);
        /*
        filesList.forEach( fileName ->{
            if (fileName.toString().contains("_cleaned_java")){
                    //JavaCollections(fileName);
                }
            else if (fileName.toString().contains("_cleaned_csharp")){
                    CSharpCollections(fileName);
                    System.exit(1);
                }
            else if(fileName.toString().contains("_cleaned_python")){
                    //PythonCollections(fileName);
                }
            }
        );*/
        filesList.forEach( fileName ->{
                    if (fileName.toString().contains("java_")){
                        JavaCollections(fileName);
                    }
                    else if (fileName.toString().contains("C#_")){
                        CSharpCollections(fileName);
                        //System.exit(1);
                    }
                    else if(fileName.toString().contains("python_")){
                        PythonCollections(fileName);
                    }
                }
        );
    }

    private static List<Path> getAllFiles(String fileName){
        Path dirPath = Paths.get(fileName);
        List<Path> fileList = null;
        try (Stream<Path> stream = Files.list(dirPath)) {
            // Collect all regular files into a List
            fileList = stream
                    .filter(Files::isRegularFile)
                    .collect(Collectors.toList());
        } catch (IOException e) {
            System.err.println("Error reading directory: " + e.getMessage());
        }
        return fileList;
    }

    private static void JavaCollections(Path path) {

        try (CSVReader reader = new CSVReader(new FileReader(path.toAbsolutePath().toString()))){
            String fileName = path.getFileName().toString();
            // Remove extension
            int dotIndex = fileName.lastIndexOf('.');
            String nameWithoutExt = (dotIndex == -1) ? fileName : fileName.substring(0, dotIndex);

            CSVWriter javaWriter =new CSVWriter(new FileWriter(content_dir + "/" + nameWithoutExt + "features.csv"));
            // read every line of the file
            String[] nextLine;
            String[] features = new String[11];
            boolean isFirstRow = true;
            while ((nextLine = reader.readNext()) != null){
                if (isFirstRow){
                    isFirstRow = false;
                    continue;
                }
                if (nextLine.length>1){
                    features[0] = nextLine[0];
                    features[1] = nextLine[1];

                    System.out.println(features[0]);
                    /// Parsing Code ///

                    CharStream input = CharStreams.fromString(features[1]);
                    JavaLexer lexer = new JavaLexer(input);
                    CommonTokenStream tokens = new CommonTokenStream(lexer);
                    JavaParser parser = new JavaParser(tokens); // Parser Created
                    ParseTree tree = parser.compilationUnit();

                    ParseTreeWalker walker = new ParseTreeWalker();
                    Listener listener = new Listener(parser);
                    walker.walk(listener, tree);

                    features[2] = Integer.toString(listener.getVariableno());
                    features[3] = Integer.toString(listener.getNoofarguments());
                    features[4] = Integer.toString(listener.getNoofoperators());
                    features[5] = Integer.toString(listener.getNoofexpression());
                    features[6] = Integer.toString(listener.getNoofloops());
                    features[7] = Integer.toString(listener.getNoofoperands());
                    features[8] = Integer.toString(listener.getNoofexceptions());
                    features[9] = Integer.toString(listener.getNoofexceptionclause());
                    features[10] = Integer.toString(listener.getMccabecomplex());

                    javaWriter.writeNext(features);
                }
            }

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (CsvValidationException e) {
            e.printStackTrace();
        }
    }
    private static void CSharpCollections(Path path){
        try (CSVReader reader = new CSVReader(new FileReader(path.toAbsolutePath().toString()))){
            String fileName = path.getFileName().toString();
            // Remove extension
            int dotIndex = fileName.lastIndexOf('.');
            String nameWithoutExt = (dotIndex == -1) ? fileName : fileName.substring(0, dotIndex);

            CSVWriter csharpWriter =new CSVWriter(new FileWriter(content_dir + "/" + nameWithoutExt + "features.csv"));
            // read every line of the file
            String[] nextLine;
            String[] features = new String[11];
            boolean isFirstRow = true;
            while ((nextLine = reader.readNext()) != null){
                if (isFirstRow){
                    isFirstRow = false;
                    continue;
                }
                if (nextLine.length>1){
                    features[0] = nextLine[0];
                    features[1] = nextLine[1];

                    System.out.println(features[0]);
                    System.out.println(features[1]);
                    /// Parsing Code ///
                    CharStream input = CharStreams.fromString(features[1]);
                    CSharpLexer lexer = new CSharpLexer(input);
                    CommonTokenStream tokens = new CommonTokenStream(lexer);
                    CSharpParser parser = new CSharpParser(tokens);
                    ParseTree tree = parser.compilation_unit();

                    ParseTreeWalker walker = new ParseTreeWalker();
                    CSharpListener listener = new CSharpListener(parser);
                    walker.walk(listener, tree);

                    features[2] = Integer.toString(listener.getNoofvariables());
                    features[3] = Integer.toString(listener.getNoofArguments());
                    features[4] = Integer.toString(listener.getNoofOperators());
                    features[5] = Integer.toString(listener.getNoofExpressions());
                    features[6] = Integer.toString(listener.getNoofLoops());
                    features[7] = Integer.toString(listener.getNoofOperands());
                    features[8] = Integer.toString(listener.getNoofExceptions());
                    features[9] = Integer.toString(listener.getNoofHandledExceptions());
                    features[10] = Integer.toString(listener.getMccabecomplex());

                    csharpWriter.writeNext(features);
                }
            }

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (CsvValidationException e) {
            e.printStackTrace();
        }
    }
    private static void PythonCollections(Path path){
        try (CSVReader reader = new CSVReader(new FileReader(path.toAbsolutePath().toString()))){
            String fileName = path.getFileName().toString();
            // Remove extension
            int dotIndex = fileName.lastIndexOf('.');
            String nameWithoutExt = (dotIndex == -1) ? fileName : fileName.substring(0, dotIndex);

            CSVWriter pythonWriter =new CSVWriter(new FileWriter(content_dir + "/" + nameWithoutExt + "features.csv"));
            // read every line of the file
            String[] nextLine;
            String[] features = new String[11];
            boolean isFirstRow = true;
            while ((nextLine = reader.readNext()) != null){
                if (isFirstRow){
                    isFirstRow = false;
                    continue;
                }
                if (nextLine.length>1){
                    features[0] = nextLine[0];
                    features[1] = nextLine[1];

                    System.out.println(features[0]);
                    /// Parsing Code ///
                    CharStream input = CharStreams.fromString(features[1]);
                    PythonLexer lexer = new PythonLexer(input);
                    CommonTokenStream tokens = new CommonTokenStream(lexer);
                    PythonParser parser = new PythonParser(tokens);
                    ParseTree tree = parser.root();

                    ParseTreeWalker walker = new ParseTreeWalker();
                    PythonListener listener = new PythonListener(parser);
                    walker.walk(listener, tree);

                    features[2] = Integer.toString(listener.getNoOfVariables());
                    features[3] = Integer.toString(listener.getNoOfArguments());
                    features[4] = Integer.toString(listener.getNoOfOperators());
                    features[5] = Integer.toString(listener.getNoOfExceptions());
                    features[6] = Integer.toString(listener.getNoOfLoops());
                    features[7] = Integer.toString(listener.getNoOfOperands());
                    features[8] = Integer.toString(listener.getNoOfExceptions());
                    features[9] = Integer.toString(listener.getNoOfExceptionClauses());
                    features[10] = Integer.toString(listener.getMccabeComplexity());

                    pythonWriter.writeNext(features);
                }
            }

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (CsvValidationException e) {
            e.printStackTrace();
        }

    }
}
