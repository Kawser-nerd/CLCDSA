package com.company;

import PythonParser.PythonParser;
import PythonParser.PythonParserBaseListener;

import java.util.HashSet;
import java.util.Set;

public class PythonListener extends PythonParserBaseListener {
    PythonParser parser;

    private int noOfVariables = 0;
    private int noOfArguments = 0;
    private int noOfExpressions = 0;
    private int noOfOperators = 0;
    private int noOfLoops = 0;
    private int noOfExceptions = 0;
    private int noOfExceptionClauses = 0;
    private int mccabeComplexity = 0;
    private int noOfOperands = 0;

    private final Set<String> nonVariableNames = new HashSet<>();
    private final Set<String> allNames = new HashSet<>();

    public PythonListener(PythonParser parser) {
        this.parser = parser;
    }

    @Override
    public void enterArgs(PythonParser.ArgsContext ctx) {
        String name = ctx.getText().replace("*", "");
        nonVariableNames.add(name);
    }

    @Override
    public void enterKwargs(PythonParser.KwargsContext ctx) {
        String name = ctx.getText().replace("*", "");
        nonVariableNames.add(name);
    }

    @Override
    public void enterDef_parameters(PythonParser.Def_parametersContext ctx) {
        String[] params = ctx.getText().replace("*", "").split(",");
        for (String param : params) {
            nonVariableNames.add(param.trim());
            noOfArguments++;
        }
    }

    @Override
    public void enterAtom(PythonParser.AtomContext ctx) {
        if (ctx.name() != null) {
            allNames.add(ctx.name().getText());
        }
    }

    @Override public void enterSwitch_stmt(PythonParser.Switch_stmtContext ctx) { mccabeComplexity++; }
    @Override public void enterRaise_stmt(PythonParser.Raise_stmtContext ctx) { noOfExceptions++; }
    @Override public void enterExcept_clause(PythonParser.Except_clauseContext ctx) { noOfExceptionClauses++; }
    @Override public void enterFinally_clause(PythonParser.Finally_clauseContext ctx) { noOfExceptionClauses++; }

    @Override
    public void enterExpr(PythonParser.ExprContext ctx) {
        if (ctx.ADD() != null || ctx.MINUS() != null || ctx.STAR() != null || ctx.DIV() != null ||
                ctx.MOD() != null || ctx.AND_OP() != null || ctx.OR_OP() != null || ctx.XOR() != null ||
                ctx.NOT_OP() != null || ctx.IDIV() != null || ctx.AT() != null ||
                ctx.LEFT_SHIFT() != null || ctx.RIGHT_SHIFT() != null || ctx.AWAIT() != null ||
                ctx.POWER() != null) {
            noOfExpressions++;
            noOfOperators++;
        }
    }

    @Override
    public void enterComparison(PythonParser.ComparisonContext ctx) {
        if (ctx.EQUALS() != null || ctx.NOT_EQ_1() != null || ctx.NOT_EQ_2() != null ||
                ctx.NOT() != null || ctx.GREATER_THAN() != null || ctx.GT_EQ() != null ||
                ctx.LESS_THAN() != null || ctx.LT_EQ() != null || ctx.IN() != null || ctx.IS() != null) {
            noOfExpressions++;
            noOfOperators++;
            mccabeComplexity++;
        }
    }

    @Override
    public void enterAssign_part(PythonParser.Assign_partContext ctx) {
        if (ctx.ASSIGN() != null || ctx.ADD_ASSIGN() != null || ctx.SUB_ASSIGN() != null ||
                ctx.MULT_ASSIGN() != null || ctx.AT_ASSIGN() != null || ctx.DIV_ASSIGN() != null ||
                ctx.MOD_ASSIGN() != null || ctx.AND_ASSIGN() != null || ctx.OR_ASSIGN() != null ||
                ctx.XOR_ASSIGN() != null || ctx.LEFT_SHIFT_ASSIGN() != null || ctx.RIGHT_SHIFT_ASSIGN() != null ||
                ctx.POWER_ASSIGN() != null || ctx.IDIV_ASSIGN() != null) {
            noOfExpressions++;
            noOfOperators++;
        }
    }

    @Override public void enterIf_stmt(PythonParser.If_stmtContext ctx) { mccabeComplexity++; }
    @Override public void enterElif_clause(PythonParser.Elif_clauseContext ctx) { mccabeComplexity++; }
    @Override public void enterElse_clause(PythonParser.Else_clauseContext ctx) { mccabeComplexity++; }
    @Override public void enterWhile_stmt(PythonParser.While_stmtContext ctx) { noOfLoops++; }
    @Override public void enterFor_stmt(PythonParser.For_stmtContext ctx) { noOfLoops++; }

    @Override
    public void enterFuncdef(PythonParser.FuncdefContext ctx) {
        if (ctx.name() != null) {
            nonVariableNames.add(ctx.name().getText());
        }
        if (ctx.getText().contains("return")) {
            noOfOperands++;
        }
    }

    private void computeFinalCounts() {
        noOfVariables = (int) allNames.stream().filter(name -> !nonVariableNames.contains(name)).count();
        noOfOperands += noOfVariables;
    }

    public int getNoOfArguments() { return noOfArguments; }
    public int getNoOfVariables() { computeFinalCounts(); return noOfVariables; }
    public int getNoOfExpressions() { return noOfExpressions; }
    public int getNoOfOperators() { return noOfOperators; }
    public int getNoOfLoops() { return noOfLoops; }
    public int getNoOfExceptions() { return noOfExceptions; }
    public int getNoOfExceptionClauses() { return noOfExceptionClauses; }
    public int getNoOfOperands() { computeFinalCounts(); return noOfOperands; }
    public int getMccabeComplexity() { return mccabeComplexity; }
}
