package com.company;

import CSharpParser.CSharpLexer;
import CSharpParser.CSharpParser;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CharStreams;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.ParseTree;
import org.antlr.v4.runtime.tree.ParseTreeWalker;

import java.io.IOException;

public class CSharpMain {
    public static void main(String[] args) throws IOException{
        CharStream input = CharStreams.fromFileName("C:\\Users\\kwnaf\\IdeaProjects\\antlrTesting\\src\\testcs.cs");
        CSharpLexer lexer = new CSharpLexer(input);
        CommonTokenStream tokens = new CommonTokenStream(lexer);
        CSharpParser parser = new CSharpParser(tokens);
        ParseTree tree = parser.compilation_unit();

        ParseTreeWalker walker = new ParseTreeWalker();
        CSharpListener listener = new CSharpListener(parser);
        walker.walk(listener, tree);

        System.out.println(listener.getNoofvariables()); // Number of Variables
        System.out.println(listener.getNoofArguments()); // Number of Arguments
        System.out.println(listener.getNoofOperators()); // No of Operators
        System.out.println(listener.getNoofExpressions()); // No of Expressions
        System.out.println(listener.getNoofLoops()); // No of Loops
        System.out.println(listener.getNoofOperands()); // No of Operands
        System.out.println(listener.getNoofExceptions()); // No of Exceptions
        System.out.println(listener.getNoofHandledExceptions()); // No of Exceptions Handled
        System.out.println(listener.getMccabecomplex()); // Mccabe Complexity
    }
}
