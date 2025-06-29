// ===== Revised Java Listener with Robust Metric Collection =====
package com.company;

import JavaParser.JavaParser;
import JavaParser.JavaParserBaseListener;
import org.antlr.v4.runtime.tree.TerminalNode;

public class Listener extends JavaParserBaseListener {
    private final JavaParser parser;
    private String className;
    private String methodName;

    private int variableno = 0;
    private int noofarguments = 0;
    private int noofexpression = 0;
    private int noofoperators = 0;
    private int noofloops = 0;
    private int noofoperands = 0;
    private int noofexceptions = 0;
    private int noofexceptionclause = 0;
    private int mccabecomplex = 0;
    private int methodCount = 0;

    public Listener(JavaParser parser) {
        this.parser = parser;
    }

    @Override
    public void enterClassDeclaration(JavaParser.ClassDeclarationContext ctx) {
        if (ctx.IDENTIFIER() != null) {
            setClassName(ctx.IDENTIFIER().getText());
        }
    }

    @Override
    public void enterMethodDeclaration(JavaParser.MethodDeclarationContext ctx) {
        if (ctx.formalParameters() != null && ctx.formalParameters().formalParameterList() != null) {
            int count = ctx.formalParameters().formalParameterList().formalParameter().size();
            noofarguments += count;
        }

        TerminalNode identifier = ctx.IDENTIFIER();
        if (identifier != null) {
            setMethodName(identifier.getText());
        }

        if (ctx.THROWS() != null) {
            noofexceptions++;
        }

        methodCount++;
        mccabecomplex++;
    }

    @Override
    public void enterCatchClause(JavaParser.CatchClauseContext ctx) {
        noofexceptionclause++;
    }

    @Override
    public void enterExpression(JavaParser.ExpressionContext ctx) {
        if (ctx.bop != null) {
            String op = ctx.bop.getText();
            if (!".".equals(op)) {
                noofoperators++;
                noofexpression++;
                if (op.matches("&&|\\|\\||==|!=|<=|>=|<|>")) {
                    mccabecomplex++;
                }

            }
        }
        if (ctx.prefix != null || ctx.postfix != null) {
            noofoperators++;
            noofexpression++;
        }
    }

    @Override
    public void enterStatement(JavaParser.StatementContext ctx) {
        if (ctx.FOR() != null || ctx.WHILE() != null || ctx.DO() != null || ctx.IF() != null) {
            mccabecomplex++;
        }
        if (ctx.FOR() != null || ctx.WHILE() != null || ctx.DO() != null) {
            noofloops++;
        }
    }

    @Override
    public void enterTypeType(JavaParser.TypeTypeContext ctx) {
        noofoperands++;
    }

    @Override
    public void enterConstantDeclarator(JavaParser.ConstantDeclaratorContext ctx) {
        noofoperands++;
    }

    @Override
    public void enterVariableDeclaratorId(JavaParser.VariableDeclaratorIdContext ctx) {
        variableno++;
    }

    @Override
    public void enterSwitchBlockStatementGroup(JavaParser.SwitchBlockStatementGroupContext ctx) {
        mccabecomplex++;
    }

    public int getNoofexpression() { return noofexpression; }
    public int getNoofloops() { return noofloops; }
    public int getNoofoperators() { return noofoperators; }
    public int getNoofoperands() { return noofoperands; }
    public int getNoofexceptions() { return noofexceptions; }
    public int getVariableno() { return variableno; }
    public int getNoofarguments() { return noofarguments; }
    public int getNoofexceptionclause() { return noofexceptionclause; }
    public int getMccabecomplex() { return mccabecomplex; }
    public String getMethodName() { return methodName; }
    public String getClassName() { return className; }
    public int getMethodCount() { return methodCount; }
    public void setClassName(String className) { this.className = className; }
    public void setMethodName(String methodName) { this.methodName = methodName; }
}
