package com.company;

import CSharpParser.CSharpParser;
import CSharpParser.CSharpParserBaseListener;

public class CSharpListener extends CSharpParserBaseListener {
    private final CSharpParser parser;

    private int noofvariables = 0;
    private int noofArguments = 0;
    private int noofExpressions = 0;
    private int noofOperators = 0;
    private int noofLoops = 0;
    private int noofExceptions = 0;
    private int noofHandledExceptions = 0;
    private int noofOperands = 0;
    private int mccabecomplex = 0;

    public CSharpListener(CSharpParser parser) {
        this.parser = parser;
    }

    // Count only in one listener to avoid duplication
    @Override
    public void enterLocal_variable_declaration(CSharpParser.Local_variable_declarationContext ctx) {
        noofvariables++;
    }

    @Override
    public void enterMethod_declaration(CSharpParser.Method_declarationContext ctx) {
        mccabecomplex++;
        if (ctx.formal_parameter_list() != null) {
            try {
                String temp = ctx.formal_parameter_list().getText();
                temp = temp.replaceAll("<[^>]*>", "");  // Remove generic types
                temp = temp.replaceAll("\\[[^\\]]*\\]", "");  // Remove array declarations
                temp = temp.trim();

                if (!temp.isEmpty()) {
                    long count = temp.chars().filter(ch -> ch == ',').count();
                    noofArguments += (int) count + 1;
                }
            } catch (Exception e) {
                // Safe fallback
                noofArguments += 0;
            }
        }
    }

    @Override
    public void enterAssignment(CSharpParser.AssignmentContext ctx) {
        noofExpressions++;
    }

    @Override
    public void enterAssignment_operator(CSharpParser.Assignment_operatorContext ctx) {
        noofOperators++;
    }

    @Override
    public void enterAdditive_expression(CSharpParser.Additive_expressionContext ctx) {
        if (ctx.PLUS().size() > 0 || ctx.MINUS().size() > 0) {
            noofOperators++;
            noofExpressions++;
        }
    }

    @Override
    public void enterMultiplicative_expression(CSharpParser.Multiplicative_expressionContext ctx) {
        if (ctx.STAR().size() > 0 || ctx.DIV().size() > 0 || ctx.PERCENT().size() > 0) {
            noofOperators++;
            noofExpressions++;
        }
    }

    @Override
    public void enterUnary_expression(CSharpParser.Unary_expressionContext ctx) {
        if (ctx.OP_INC() != null || ctx.OP_DEC() != null) {
            noofOperators++;
            noofExpressions++;
        }
    }

    @Override
    public void enterEquality_expression(CSharpParser.Equality_expressionContext ctx) {
        if (ctx.OP_EQ().size() > 0 || ctx.OP_NE().size() > 0) {
            noofOperators++;
            noofExpressions++;
        }
    }

    @Override
    public void enterRelational_expression(CSharpParser.Relational_expressionContext ctx) {
        if (ctx.GT().size() > 0 || ctx.LT().size() > 0 ||
                ctx.OP_GE().size() > 0 || ctx.OP_LE().size() > 0 || ctx.IS().size() > 0) {
            noofOperators++;
            noofExpressions++;
        }
    }

    @Override
    public void enterConditional_and_expression(CSharpParser.Conditional_and_expressionContext ctx) {
        if (ctx.OP_AND().size() > 0) {
            noofOperators++;
            noofExpressions++;
            mccabecomplex++;
        }
    }

    @Override
    public void exitConditional_or_expression(CSharpParser.Conditional_or_expressionContext ctx) {
        if (ctx.OP_OR().size() > 0) {
            noofOperators++;
            noofExpressions++;
            mccabecomplex++;
        }
    }

    @Override
    public void enterShift_expression(CSharpParser.Shift_expressionContext ctx) {
        if (ctx.OP_LEFT_SHIFT().size() > 0 || ctx.right_shift().size() > 0) {
            noofOperators++;
            noofExpressions++;
        }
    }

    @Override
    public void enterIfStatement(CSharpParser.IfStatementContext ctx) {
        if (ctx.IF() != null) {
            mccabecomplex++;
        }
        // We skip `else` since it doesn't add to complexity unless it's "else if"
    }

    @Override
    public void enterForStatement(CSharpParser.ForStatementContext ctx) {
        noofLoops++;
        mccabecomplex++;
    }

    @Override
    public void enterForeachStatement(CSharpParser.ForeachStatementContext ctx) {
        noofLoops++;
        mccabecomplex++;
    }

    @Override
    public void enterWhileStatement(CSharpParser.WhileStatementContext ctx) {
        noofLoops++;
        mccabecomplex++;
    }

    @Override
    public void enterDoStatement(CSharpParser.DoStatementContext ctx) {
        noofLoops++;
        mccabecomplex++;
    }

    @Override
    public void enterThrowStatement(CSharpParser.ThrowStatementContext ctx) {
        noofExceptions++;
    }

    @Override
    public void enterCatch_clauses(CSharpParser.Catch_clausesContext ctx) {
        noofHandledExceptions++;
    }

    @Override
    public void enterType_(CSharpParser.Type_Context ctx) {
        if (ctx.base_type() != null) {
            if (ctx.base_type().class_type() != null) {
                if (ctx.base_type().class_type().STRING() != null || ctx.base_type().class_type().DYNAMIC() != null) {
                    noofOperands++;
                }
            } else if (ctx.base_type().simple_type() != null) {
                if (ctx.base_type().simple_type().BOOL() != null) {
                    noofOperands++;
                } else if (ctx.base_type().simple_type().numeric_type() != null) {
                    if (ctx.base_type().simple_type().numeric_type().integral_type() != null ||
                            ctx.base_type().simple_type().numeric_type().floating_point_type() != null ||
                            ctx.base_type().simple_type().numeric_type().DECIMAL() != null) {
                        noofOperands++;
                    }
                }
            }
        }
    }

    @Override
    public void enterSwitch_label(CSharpParser.Switch_labelContext ctx) {
        mccabecomplex++;
    }

    // === Getters ===
    public int getNoofvariables() {
        return noofvariables;
    }

    public int getNoofArguments() {
        return noofArguments;
    }

    public int getNoofOperators() {
        return noofOperators;
    }

    public int getNoofExpressions() {
        return noofExpressions;
    }

    public int getNoofLoops() {
        return noofLoops;
    }

    public int getNoofExceptions() {
        return noofExceptions;
    }

    public int getNoofHandledExceptions() {
        return noofHandledExceptions;
    }

    public int getNoofOperands() {
        return noofOperands;
    }

    public int getMccabecomplex() {
        return mccabecomplex;
    }
}
