package com.company;

import PythonParser.PythonParser;
import PythonParser.PythonParserBaseListener;

import java.util.ArrayList;

public class PythonListener  extends PythonParserBaseListener {
    PythonParser parser;

    private int noofVariable = 0;
    private int noofArguments = 0;
    private int noofExpressions = 0;
    private int noofOperators = 0;
    private int noofloops = 0;
    private int noofexceptions = 0;
    private int noofexceptionclause = 0;
    private int mccabecomplexity = 0;
    private int noofOperands = 0;

    private ArrayList<String> nonVariableList = new ArrayList<String>();
    private ArrayList<String> varList = new ArrayList<String>();

    public PythonListener(PythonParser parser){
        this.parser = parser;
    }

    @Override public void enterArgs(PythonParser.ArgsContext ctx) {
        String temp = ctx.getText();
        temp = temp.replace("*","");
        if(!nonVariableList.contains(temp))
            nonVariableList.add(temp);
    }
    @Override public void enterKwargs(PythonParser.KwargsContext ctx) {
        String temp = ctx.getText();
        temp = temp.replace("*", "");
        if(!nonVariableList.contains(temp))
            nonVariableList.add(temp);
    }

    @Override public void enterDef_parameters(PythonParser.Def_parametersContext ctx) { // all the function parameters
        String temp = ctx.getText();
        String[] tmp = temp.split(",");
        for (int i =0; i < tmp.length; i++){
            if(!nonVariableList.contains(tmp[i]))
                nonVariableList.add(tmp[i]);
            noofArguments++;
        }
    }

    /// Variable names need to derive
    @Override public void enterAtom(PythonParser.AtomContext ctx) {
        if (ctx.name()!=null) {
            String temp = ctx.name().getText();
            if (!varList.contains(temp))
                varList.add(temp);
        }
    }

    @Override public void enterSwitch_stmt(PythonParser.Switch_stmtContext ctx) {
        mccabecomplexity++;
    }

    @Override public void enterRaise_stmt(PythonParser.Raise_stmtContext ctx) {
        noofexceptions++;
    }

    @Override public void enterExcept_clause(PythonParser.Except_clauseContext ctx) {
        noofexceptionclause++;
    }

    @Override public void enterFinally_clause(PythonParser.Finally_clauseContext ctx) {
        noofexceptionclause++;
    }

    // List all the operators //
    @Override public void enterExpr(PythonParser.ExprContext ctx) {
        if(ctx.ADD()!=null){
            noofExpressions++;
            noofOperators++;
        } else if(ctx.MINUS()!= null){
            noofExpressions++;
            noofOperators++;
        } else if(ctx.STAR()!= null){
            noofExpressions++;
            noofOperators++;
        } else if(ctx.DIV()!= null){
            noofExpressions++;
            noofOperators++;
        } else if(ctx.MOD()!=null){
            noofExpressions++;
            noofOperators++;
        } else if(ctx.AND_OP()!= null){
            noofExpressions++;
            noofOperators++;
        } else if(ctx.OR_OP()!= null){
            noofExpressions++;
            noofOperators++;
        } else if(ctx.XOR()!= null){
            noofExpressions++;
            noofOperators++;
        } else if(ctx.NOT_OP()!= null){
            noofExpressions++;
            noofOperators++;
        } else if(ctx.IDIV()!= null){
            noofExpressions++;
            noofOperators++;
        } else if(ctx.AT()!=null){
            noofExpressions++;
            noofOperators++;
        } else if(ctx.LEFT_SHIFT()!=null){
            noofExpressions++;
            noofOperators++;
        } else if(ctx.RIGHT_SHIFT()!= null){
            noofExpressions++;
            noofOperators++;
        } else if(ctx.AWAIT()!= null){
            noofExpressions++;
            noofOperators++;
        } else if(ctx.POWER()!=null){
            noofExpressions++;
            noofOperators++;
        }
    }

    // Boolean Operation //
    @Override public void enterComparison(PythonParser.ComparisonContext ctx) {
        if(ctx.EQUALS()!=null){
            noofExpressions++;
            noofOperators++;
            mccabecomplexity++;
        } else if(ctx.NOT_EQ_1()!=null){
            noofExpressions++;
            noofOperators++;
            mccabecomplexity++;
        } else if(ctx.NOT_EQ_2()!=null){
            noofExpressions++;
            noofOperators++;
            mccabecomplexity++;
        } else if(ctx.NOT()!=null){
            noofExpressions++;
            noofOperators++;
            mccabecomplexity++;
        } else if(ctx.GREATER_THAN()!=null) {
            noofExpressions++;
            noofOperators++;
            mccabecomplexity++;
        } else if(ctx.GT_EQ()!= null){
            noofExpressions++;
            noofOperators++;
            mccabecomplexity++;
        } else if(ctx.LESS_THAN()!=null){
            noofExpressions++;
            noofOperators++;
            mccabecomplexity++;
        } else if(ctx.LT_EQ()!=null){
            noofExpressions++;
            noofOperators++;
            mccabecomplexity++;
        } else if(ctx.IN()!=null){
            noofExpressions++;
            noofOperators++;
            mccabecomplexity++;
        } else if(ctx.IS()!= null){
            noofExpressions++;
            noofOperators++;
            mccabecomplexity++;
        }
    }


    @Override public void enterStmt(PythonParser.StmtContext ctx) {
        //System.out.println(ctx.getText());
      /*
        if(ctx.simple_stmt()!=null) {
            if(!ctx.simple_stmt().getText().contains("from"))
                noofExpressions++;
        }
        else if(ctx.compound_stmt()!= null){
            if(!ctx.compound_stmt().getText().contains("from")){
                noofExpressions++;
            }
        }
        */
    }

    // All Assignment operation/ mathematical operation //
    @Override public void enterAssign_part(PythonParser.Assign_partContext ctx) {
        if(ctx.ASSIGN()!=null){
            noofExpressions++;
            noofOperators++;
        } else if(ctx.ADD_ASSIGN()!=null){
            noofExpressions++;
            noofOperators++;
        } else if(ctx.SUB_ASSIGN()!=null){
            noofExpressions++;
            noofOperators++;
        } else if(ctx.MULT_ASSIGN()!=null){
            noofExpressions++;
            noofOperators++;
        } else if(ctx.AT_ASSIGN()!=null){
            noofExpressions++;
            noofOperators++;
        } else if(ctx.DIV_ASSIGN()!=null){
            noofExpressions++;
            noofOperators++;
        } else if(ctx.MOD_ASSIGN()!=null){
            noofExpressions++;
            noofOperators++;
        } else if(ctx.AND_ASSIGN()!=null){
            noofExpressions++;
            noofOperators++;
        } else if(ctx.OR_ASSIGN()!=null){
            noofExpressions++;
            noofOperators++;
        }  else if(ctx.XOR_ASSIGN()!=null){
            noofExpressions++;
            noofOperators++;
        } else if(ctx.LEFT_SHIFT_ASSIGN()!=null){
            noofExpressions++;
            noofOperators++;
        } else if(ctx.RIGHT_SHIFT_ASSIGN()!=null){
            noofExpressions++;
            noofOperators++;
        } else if(ctx.POWER_ASSIGN()!=null){
            noofExpressions++;
            noofOperators++;
        } else if(ctx.IDIV_ASSIGN()!=null){
            noofExpressions++;
            noofOperators++;
        }
    }

    @Override public void enterIf_stmt(PythonParser.If_stmtContext ctx) {
            mccabecomplexity++;
    }

    @Override public void enterElif_clause(PythonParser.Elif_clauseContext ctx) {
        mccabecomplexity++;
    }

    @Override public void enterElse_clause(PythonParser.Else_clauseContext ctx) {
        mccabecomplexity++;
    }

    @Override public void enterWhile_stmt(PythonParser.While_stmtContext ctx) {
        noofloops++;
    }

    @Override public void enterFor_stmt(PythonParser.For_stmtContext ctx) {
        noofloops++;
    }

    @Override public void enterFuncdef(PythonParser.FuncdefContext ctx) { // this step is required to delete non-variable items from
        if(ctx.name()!=null){   // ALl the function names are returned.
            if(!nonVariableList.contains(ctx.name().getText()))
                nonVariableList.add(ctx.name().getText());
        }

        if(ctx.getText().contains("return")) // To define Type. Functions with all
            noofOperands++;
    }

    private void setVarCount()
    {
        this.noofVariable = varList.size() - nonVariableList.size();
        this.noofOperands = this.noofOperands + this.noofVariable;
    }

    public int getNoofArguments() {
        return noofArguments;
    }
    public int getNoofVariable() {
        setVarCount();
        return this.noofVariable;
    }
    public int getNoofExpressions(){
        return this.noofExpressions;
    }
    public int getNoofOperators(){
        return noofOperators;
    }
    public int getNoofloops(){
        return noofloops;
    }
    public int getNoofexceptions(){
        return noofexceptions;
    }
    public int getNoofexceptionclause(){
        return noofexceptionclause;
    }
    public int getNoofOperands(){
        return noofOperands;
    }
    public int getMccabecomplexity(){
        return mccabecomplexity;
    }
}
