package com.company;

import CSharpParser.CSharpLexer;
import CSharpParser.CSharpParser;
import JavaParser.JavaLexer;
import JavaParser.JavaParser;
import PythonParser.PythonLexer;
import PythonParser.PythonParser;
import com.opencsv.CSVWriter;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CharStreams;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.ParseTree;
import org.antlr.v4.runtime.tree.ParseTreeWalker;

import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Collections;
import java.util.List;
import java.util.Locale;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.stream.Stream;

import static java.util.stream.Collectors.*;

public class DataCollection {
    private static String datafolder = "./Source Codes";

    public static void main(String[] args) throws IOException {
        String fileExtenstion = "java";

        List<Path> allFiles = listAllFiles(fileExtenstion);
        AtomicInteger count = new AtomicInteger();

        switch (fileExtenstion){
            case "java":
                CSVWriter javaWriter =new CSVWriter(new FileWriter("./JavaCodeFeatureFiles.csv"));
                allFiles.forEach(x -> {
                    try {
                        JavaCollection(x.toAbsolutePath(), javaWriter);
                        count.getAndIncrement();
                        if(count.get() % 500 == 0)
                            System.out.println("File no traversed: " + count.toString());
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                });
                javaWriter.close();
                break;
            case "csharp":
                CSVWriter csharpWriter =new CSVWriter(new FileWriter("./CSharpCodeFeatureFiles.csv"));
                allFiles.forEach(x -> {
                    try {
                        CSharpCollection(x.toAbsolutePath(), csharpWriter);
                        count.getAndIncrement();
                        if(count.get() % 500 == 0)
                            System.out.println("File no traversed: " + count.toString());
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                });
                csharpWriter.close();
                break;
            case "python":
                CSVWriter pythonWriter =new CSVWriter(new FileWriter("./PythonCodeFeatureFiles.csv"));
                allFiles.forEach(x -> {
                    try {
                        PythonCollection(x.toAbsolutePath(), pythonWriter);
                        count.getAndIncrement();
                        if(count.get() % 500 == 0)
                            System.out.println("File no traversed: " + count.toString());
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                });
                pythonWriter.close();
                break;
            default:
                System.out.println("Not proper fileExtension was provided. Check the file extension carefully");
        }
    }

    private static List<Path> listAllFiles( String extension) throws IOException {
        Path path = Paths.get(datafolder);
        List<Path> allfiles;

        switch (extension.toLowerCase(Locale.ROOT)){
            case "java":
                try (Stream<Path> walk = Files.walk(path.toAbsolutePath())) {
                    allfiles = walk.filter(Files::isRegularFile).filter(x -> x.getFileName().toString().endsWith(".java"))
                            .collect(toList());
                }
                break;
            case "csharp":
                try (Stream<Path> walk = Files.walk(path.toAbsolutePath())) {
                    allfiles = walk.filter(Files::isRegularFile).filter(x -> x.getFileName().toString().endsWith(".cs"))
                            .collect(toList());
                }
                break;
            case "python":
                try (Stream<Path> walk = Files.walk(path.toAbsolutePath())) {
                    allfiles = walk.filter(Files::isRegularFile).filter(x -> x.getFileName().toString().endsWith(".py"))
                            .collect(toList());
                }
                break;
            default:
                System.out.println("Proper file extension wasn't given or found in the directory");
                allfiles = Collections.<Path>emptyList();
        }

        return allfiles;
    }

    private static void JavaCollection(Path path, CSVWriter writer) throws IOException {
        String[] features = new String[10];
        features[0] = path.getParent().toString();

        /// Parsing Code ///
        CharStream input = CharStreams.fromFileName(String.valueOf(path.toAbsolutePath()));
        JavaLexer lexer = new JavaLexer(input);
        CommonTokenStream tokens = new CommonTokenStream(lexer);
        JavaParser parser = new JavaParser(tokens); // Parser Created
        ParseTree tree = parser.compilationUnit();

        ParseTreeWalker walker = new ParseTreeWalker();
        Listener listener = new Listener(parser);
        walker.walk(listener, tree);

        features[1] = Integer.toString(listener.getVariableno());
        features[2] = Integer.toString(listener.getNoofarguments());
        features[3] = Integer.toString(listener.getNoofoperators());
        features[4] = Integer.toString(listener.getNoofexpression());
        features[5] = Integer.toString(listener.getNoofloops());
        features[6] = Integer.toString(listener.getNoofoperands());
        features[7] = Integer.toString(listener.getNoofexceptions());
        features[8] = Integer.toString(listener.getNoofexceptionclause());
        features[9] = Integer.toString(listener.getMccablecomplex());

        int totalFeatureValue = 0;
        for(int i = 1; i < features.length; i++)
            totalFeatureValue = totalFeatureValue + Integer.parseInt(features[i]);

        if(totalFeatureValue>0)
            writer.writeNext(features);

    }
    private static void CSharpCollection(Path path, CSVWriter writer) throws IOException {
        String[] features = new String[10];
        features[0] = path.getParent().toString();

        /// Parsing Code ///
        CharStream input = CharStreams.fromFileName(String.valueOf(path.toAbsolutePath()));
        CSharpLexer lexer = new CSharpLexer(input);
        CommonTokenStream tokens = new CommonTokenStream(lexer);
        CSharpParser parser = new CSharpParser(tokens);
        ParseTree tree = parser.compilation_unit();

        ParseTreeWalker walker = new ParseTreeWalker();
        CSharpListener listener = new CSharpListener(parser);
        walker.walk(listener, tree);

        features[1] = Integer.toString(listener.getNoofvariables());
        features[2] = Integer.toString(listener.getNoofArguments());
        features[3] = Integer.toString(listener.getNoofOperators());
        features[4] = Integer.toString(listener.getNoofExpressions());
        features[5] = Integer.toString(listener.getNoofLoops());
        features[6] = Integer.toString(listener.getNoofOperands());
        features[7] = Integer.toString(listener.getNoofExceptions());
        features[8] = Integer.toString(listener.getNoofHandledExceptions());
        features[9] = Integer.toString(listener.getMccabecomplex());

        int totalFeatureValue = 0;
        for(int i = 1; i < features.length; i++)
            totalFeatureValue = totalFeatureValue + Integer.parseInt(features[i]);

        if(totalFeatureValue>0)
            writer.writeNext(features);
    }
    private static void PythonCollection(Path path, CSVWriter writer) throws IOException {
        String[] features = new String[10];
        features[0] = path.getParent().toString();

        /// Parsing Code ///
        CharStream input = CharStreams.fromFileName(String.valueOf(path.toAbsolutePath()));
        PythonLexer lexer = new PythonLexer(input);
        CommonTokenStream tokens = new CommonTokenStream(lexer);
        PythonParser parser = new PythonParser(tokens);
        ParseTree tree = parser.root();

        ParseTreeWalker walker = new ParseTreeWalker();
        PythonListener listener = new PythonListener(parser);
        walker.walk(listener, tree);

        features[1] = Integer.toString(listener.getNoofVariable());
        features[2] = Integer.toString(listener.getNoofArguments());
        features[3] = Integer.toString(listener.getNoofOperators());
        features[4] = Integer.toString(listener.getNoofExpressions());
        features[5] = Integer.toString(listener.getNoofloops());
        features[6] = Integer.toString(listener.getNoofOperands());
        features[7] = Integer.toString(listener.getNoofexceptions());
        features[8] = Integer.toString(listener.getNoofexceptionclause());
        features[9] = Integer.toString(listener.getMccabecomplexity());

        int totalFeatureValue = 0;
        for(int i = 1; i < features.length; i++)
            totalFeatureValue = totalFeatureValue + Integer.parseInt(features[i]);

        if(totalFeatureValue>0)
            writer.writeNext(features);

    }
}
