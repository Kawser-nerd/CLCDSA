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
        CharStream input = CharStreams.fromFileName("C:\\Users\\kwnaf\\IdeaProjects\\antlrTesting\\src\\testpy.py");
        PythonLexer lexer = new PythonLexer(input);
        CommonTokenStream tokens = new CommonTokenStream(lexer);
        PythonParser parser = new PythonParser(tokens);
        ParseTree tree = parser.root();

        ParseTreeWalker walker = new ParseTreeWalker();
        PythonListener listener = new PythonListener(parser);
        walker.walk(listener, tree);

        System.out.println(listener.getNoofVariable()); // Number of variables
        System.out.println(listener.getNoofArguments()); // Number of Arguments
        System.out.println(listener.getNoofOperators()); // Number of Operators
        System.out.println(listener.getNoofExpressions()); // Number of Expressions
        System.out.println(listener.getNoofloops()); // Number of Loops
        System.out.println(listener.getNoofOperands()); // Number of Operands
        System.out.println(listener.getNoofexceptions()); // Number of Exceptions Called
        System.out.println(listener.getNoofexceptionclause()); // Number of Exception Handled
        System.out.println(listener.getMccabecomplexity()); // Mccabe Complexity
    }
}
