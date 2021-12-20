package com.company;

import JavaParser.JavaParserBaseListener;
import JavaParser.JavaParser;
import org.antlr.v4.runtime.tree.TerminalNode;

public class Listener extends JavaParserBaseListener {

    /** Observable. */
    JavaParser parser;

    /** The clazzName of the imported file. */
    private String className;
    private String methodName;
    private int variableno =0 ;
    private int noofarguments = 0;
    private int noofexpression = 0;
    private int noofoperators = 0;
    private int noofloops = 0;
    private int noofoperands = 0;
    private int noofexceptions = 0;
    private int noofexceptionclause = 0;
    private int mccablecomplex = 0;
    private int testvalue = 0;

    /** The count of methdos of the imported file. */
    private int methodCount;

    public Listener(JavaParser parser) {
        this.parser = parser;
    }

    /** Listen to matches of classDeclaration */
    @Override
    public void enterClassDeclaration(JavaParser.ClassDeclarationContext ctx) {
        setClassName(ctx.IDENTIFIER().toString());
    }

    /** Listen to matches of methodDeclaration */
    @Override
    public void enterMethodDeclaration(JavaParser.MethodDeclarationContext ctx) {
        methodargument(ctx.formalParameters().getText());
        methodCount++;
        mccablecomplex++;

        TerminalNode identifier = ctx.IDENTIFIER();
        if(identifier != null)
        {
            setMethodName(identifier.getText());
        }
        if(ctx.THROWS()!= null)
            noofexceptions++;
    }

    @Override public void enterCatchClause(JavaParser.CatchClauseContext ctx) {
        noofexceptionclause++;
    }

    @Override
    public void enterVariableInitializer(JavaParser.VariableInitializerContext ctx) {
        variableno++;
    }

    /*
    @Override
    public void enterArguments(JavaParser.ArgumentsContext ctx) {
        System.out.println(ctx.getText());
        noofarguments++;
    }
    */

    public void methodargument(String parameters)
    {
        parameters = parameters.replace("(", "");
        parameters = parameters.replace(")", "");
        if (!parameters.isEmpty()){
            int count = (int) parameters.chars().filter(ch -> ch == ',').count();
            noofarguments = noofarguments + count + 1;
        }

    }

    @Override
    public void enterTypeArgument(JavaParser.TypeArgumentContext ctx) {
        noofoperands++;
    }
    @Override
    public void enterExpression(JavaParser.ExpressionContext ctx) {
        if (ctx.bop != null) {
            String temp = ctx.bop.getText();
            if (!temp.equals(".")) {
                if (temp.equals("+") || temp.equals("-") || temp.equals("*") || temp.equals("/") || temp.equals("%")
                || temp.equals("=") || temp.equals("+=") || temp.equals("-=") || temp.equals("*=") || temp.equals("/=")
                        || temp.equals("&=") || temp.equals("|=") || temp.equals("^=") || temp.equals(">>=") ||
                        temp.equals(">>>=") || temp.equals("<<=") || temp.equals("%=")) {
                    noofoperators++;
                    noofexpression++;
                }
                else if(temp.equals("&&") || temp.equals("||") || temp.equals("!") || temp.equals("==") || temp.equals("!=")
                || temp.equals(">") || temp.equals("<") || temp.equals(">=") || temp.equals("<=")){
                    noofoperators++;
                    noofexpression++;
                    mccablecomplex++;
                }
            }
        }
        if(ctx.prefix != null) {
            String temp = ctx.prefix.getText();
            if (temp.equals("++") || temp.equals("--") ) {
                noofoperators++;
                noofexpression++;
            }
        }

        if(ctx.postfix != null){
            String temp = ctx.postfix.getText();
            if (temp.equals("++") || temp.equals("--") ) {
                noofoperators++;
                noofexpression++;
            }
        }
    }

    @Override
    public void enterArrayInitializer(JavaParser.ArrayInitializerContext ctx) {
        variableno++;
    }



    @Override
    public void enterConstantDeclarator(JavaParser.ConstantDeclaratorContext ctx) {
        noofoperands++;
    }

    @Override public void enterTypeType(JavaParser.TypeTypeContext ctx) {
        noofoperands++;
    }


    @Override
    public void enterStatement(JavaParser.StatementContext ctx) {
        if (ctx.FOR() != null || ctx.WHILE() != null || ctx.DO() != null) {
            noofloops++;
            mccablecomplex++;
        }
        if(ctx.IF() != null) {
            mccablecomplex++;
        }
    }

    @Override public void enterSwitchBlockStatementGroup(JavaParser.SwitchBlockStatementGroupContext ctx) {
        mccablecomplex++;

    }

    public int getNoofexpression(){
       return noofexpression;
    }
    public int getNoofloops(){
        return noofloops;
    }
    public int getNoofoperators(){
        return noofoperators;
    }

    public void setMethodName(String MethodNme)
    {
        methodName = MethodNme;
    }

    public int getNoofoperands(){
        return noofoperands;
    }

    public int getNoofexceptions(){
        return noofexceptions;
    }

    public int getVariableno()
    {
        return variableno;
    }

    public int getNoofarguments()
    {
        return noofarguments;
    }
    public int getNoofexceptionclause(){
        return noofexceptionclause;
    }
    public int getTestvalue(){
        return testvalue;
    }
    public int getMccablecomplex(){
        return mccablecomplex;
    }

    public String getMethodName() {
        return methodName;
    }

    public String getClassName() {
        return className;
    }

    public void setClassName(String className) {
        this.className = className;
    }

    public int getMethodCount() {
        return methodCount;
    }

    public void setMethodCount(int methodCount) {
        this.methodCount = methodCount;
    }
}
