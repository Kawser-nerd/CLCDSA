package com.company;


import PythonParser.PythonLexer;
import PythonParser.PythonParser;
import PythonParser.PythonParserBaseVisitor;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CharStreams;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.ParseTree;
import org.antlr.v4.runtime.tree.ParseTreeWalker;

import java.io.IOException;

public class PythonMain  extends PythonParserBaseVisitor {
    public static void main(String[] args) throws IOException {
        CharStream input = CharStreams.fromFileName("C:\\Users\\kawser\\IdeaProjects\\CLCDSA\\CLCDSA_Code\\src\\testpy.py");
        PythonLexer lexer = new PythonLexer(input);
        CommonTokenStream tokens = new CommonTokenStream(lexer);
        PythonParser parser = new PythonParser(tokens);
        ParseTree tree = parser.root();

        ParseTreeWalker walker = new ParseTreeWalker();
        PythonListener listener = new PythonListener(parser);
        walker.walk(listener, tree);

        System.out.println(listener.getNoOfVariables()); // Number of variables
        System.out.println(listener.getNoOfArguments()); // Number of Arguments
        System.out.println(listener.getNoOfOperators()); // Number of Operators
        System.out.println(listener.getNoOfExpressions()); // Number of Expressions
        System.out.println(listener.getNoOfLoops()); // Number of Loops
        System.out.println(listener.getNoOfOperands()); // Number of Operands
        System.out.println(listener.getNoOfExceptions()); // Number of Exceptions Called
        System.out.println(listener.getNoOfExceptionClauses()); // Number of Exception Handled
        System.out.println(listener.getMccabeComplexity()); // Mccabe Complexity
    }
}
