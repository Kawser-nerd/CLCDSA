package com.company;

import CSharpParser.CSharpLexer;
import CSharpParser.CSharpParser;
import JavaParser.JavaLexer;
import JavaParser.JavaParser;
import PythonParser.PythonLexer;
import PythonParser.PythonParser;
import com.opencsv.CSVParserBuilder;
import com.opencsv.CSVReader;
import com.opencsv.CSVReaderBuilder;
import com.opencsv.CSVWriter;
import com.opencsv.exceptions.CsvValidationException;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CharStreams;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.ParseTree;
import org.antlr.v4.runtime.tree.ParseTreeWalker;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;

public class GPTFeatureModification {
    static String content_dir = "Source Codes/GPTCloneBench";
    static File[] folders = getFolders(content_dir);
    static String[] header = {"fileName","code","feature1","feature2","feature3", "feature4", "feature5", "feature6",
            "feature7", "feature8", "feature9"};

    public static void main(String[] args) {
        for(File folder : folders){
            String lang = folder.getName().split("_")[0].toString();
            System.out.println(folder.toString());

            if(lang.equals("csharp"))
                getCsharpFeatures(folder, lang);
            else if(lang.equals("java"))
                getJavaFeatures(folder, lang);
            else if(lang.equals("python"))
                getPythonFeatures(folder, lang);

        }
    }

    private static File[] getFolders(String content_dir){
        File parentDir = new File(content_dir);
        File[] folders = parentDir.listFiles(File::isDirectory);
        return folders;
    }

    private static File[] getFiles(String fileDir){
        File folder = new File(fileDir);
        File[] files = folder.listFiles(File::isFile);
        return files;
    }

    private static void getCsharpFeatures(File folder, String fileprefix){

        try {
            CSVWriter csvWriter = new CSVWriter(new FileWriter(folder.toString() +"/" +fileprefix + "_gptclonebench.csv"));
            csvWriter.writeNext(header);
            String[] features = new String[11];
            File[] codeFiles = getFiles(folder.toString());
            for(File codeFile : codeFiles){
                String fileName = codeFile.getName().toString();
                // Remove extension
                int dotIndex = fileName.lastIndexOf('.');
                features[0] = (dotIndex == -1) ? fileName : fileName.substring(0, dotIndex);

                /// Parsing Code ///
                CharStream input = CharStreams.fromFileName(codeFile.toString());
                CSharpLexer lexer = new CSharpLexer(input);
                CommonTokenStream tokens = new CommonTokenStream(lexer);
                CSharpParser parser = new CSharpParser(tokens);
                ParseTree tree = parser.compilation_unit();

                ParseTreeWalker walker = new ParseTreeWalker();
                CSharpListener listener = new CSharpListener(parser);
                walker.walk(listener, tree);
                features[1] = new String(Files.readAllBytes(Paths.get(codeFile.toString())));
                features[2] = Integer.toString(listener.getNoofvariables());
                features[3] = Integer.toString(listener.getNoofArguments());
                features[4] = Integer.toString(listener.getNoofOperators());
                features[5] = Integer.toString(listener.getNoofExpressions());
                features[6] = Integer.toString(listener.getNoofLoops());
                features[7] = Integer.toString(listener.getNoofOperands());
                features[8] = Integer.toString(listener.getNoofExceptions());
                features[9] = Integer.toString(listener.getNoofHandledExceptions());
                features[10] = Integer.toString(listener.getMccabecomplex());

                csvWriter.writeNext(features);

            }

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    private static void getJavaFeatures(File folder, String fileprefix){
        try {
            CSVWriter csvWriter = new CSVWriter(new FileWriter(folder.toString() + "/" + fileprefix + "_gptclonebench.csv"));
            csvWriter.writeNext(header);
            String[] features = new String[11];
            File[] codeFiles = getFiles(folder.toString());
            for (File codeFile : codeFiles) {
                String fileName = codeFile.getName().toString();
                // Remove extension
                int dotIndex = fileName.lastIndexOf('.');
                features[0] = (dotIndex == -1) ? fileName : fileName.substring(0, dotIndex);

                CharStream input = CharStreams.fromFileName(codeFile.toString());
                JavaLexer lexer = new JavaLexer(input);
                CommonTokenStream tokens = new CommonTokenStream(lexer);
                JavaParser parser = new JavaParser(tokens); // Parser Created
                ParseTree tree = parser.compilationUnit();

                ParseTreeWalker walker = new ParseTreeWalker();
                Listener listener = new Listener(parser);
                walker.walk(listener, tree);

                features[1] = new String(Files.readAllBytes(Paths.get(codeFile.toString())));
                features[2] = Integer.toString(listener.getVariableno());
                features[3] = Integer.toString(listener.getNoofarguments());
                features[4] = Integer.toString(listener.getNoofoperators());
                features[5] = Integer.toString(listener.getNoofexpression());
                features[6] = Integer.toString(listener.getNoofloops());
                features[7] = Integer.toString(listener.getNoofoperands());
                features[8] = Integer.toString(listener.getNoofexceptions());
                features[9] = Integer.toString(listener.getNoofexceptionclause());
                features[10] = Integer.toString(listener.getMccabecomplex());

                csvWriter.writeNext(features);
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void getPythonFeatures(File folder, String fileprefix) {
        try{
            CSVWriter csvWriter = new CSVWriter(new FileWriter(folder.toString() + "/" + fileprefix + "_gptclonebench.csv"));
            csvWriter.writeNext(header);
            String[] features = new String[11];
            File[] codeFiles = getFiles(folder.toString());
            for (File codeFile : codeFiles) {
                String fileName = codeFile.getName().toString();
                // Remove extension
                int dotIndex = fileName.lastIndexOf('.');
                features[0] = (dotIndex == -1) ? fileName : fileName.substring(0, dotIndex);

                /// Parsing Code ///
                CharStream input = CharStreams.fromFileName(codeFile.toString());
                PythonLexer lexer = new PythonLexer(input);
                CommonTokenStream tokens = new CommonTokenStream(lexer);
                PythonParser parser = new PythonParser(tokens);
                ParseTree tree = parser.root();

                ParseTreeWalker walker = new ParseTreeWalker();
                PythonListener listener = new PythonListener(parser);
                walker.walk(listener, tree);

                features[1] = new String(Files.readAllBytes(Paths.get(codeFile.toString())));
                features[2] = Integer.toString(listener.getNoOfVariables());
                features[3] = Integer.toString(listener.getNoOfArguments());
                features[4] = Integer.toString(listener.getNoOfOperators());
                features[5] = Integer.toString(listener.getNoOfExpressions());
                features[6] = Integer.toString(listener.getNoOfLoops());
                features[7] = Integer.toString(listener.getNoOfOperands());
                features[8] = Integer.toString(listener.getNoOfExceptions());
                features[9] = Integer.toString(listener.getNoOfExceptionClauses());
                features[10] = Integer.toString(listener.getMccabeComplexity());

                csvWriter.writeNext(features);
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
