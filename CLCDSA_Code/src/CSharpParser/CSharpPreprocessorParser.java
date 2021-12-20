// Generated from C:/Users/kwnaf/IdeaProjects/antlrTesting\CSharpPreprocessorParser.g4 by ANTLR 4.9.2
package CSharpParser;
import java.util.Stack;
import java.util.HashSet;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class CSharpPreprocessorParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.9.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		BYTE_ORDER_MARK=1, SINGLE_LINE_DOC_COMMENT=2, EMPTY_DELIMITED_DOC_COMMENT=3, 
		DELIMITED_DOC_COMMENT=4, SINGLE_LINE_COMMENT=5, DELIMITED_COMMENT=6, WHITESPACES=7, 
		SHARP=8, ABSTRACT=9, ADD=10, ALIAS=11, ARGLIST=12, AS=13, ASCENDING=14, 
		ASYNC=15, AWAIT=16, BASE=17, BOOL=18, BREAK=19, BY=20, BYTE=21, CASE=22, 
		CATCH=23, CHAR=24, CHECKED=25, CLASS=26, CONST=27, CONTINUE=28, DECIMAL=29, 
		DEFAULT=30, DELEGATE=31, DESCENDING=32, DO=33, DOUBLE=34, DYNAMIC=35, 
		ELSE=36, ENUM=37, EQUALS=38, EVENT=39, EXPLICIT=40, EXTERN=41, FALSE=42, 
		FINALLY=43, FIXED=44, FLOAT=45, FOR=46, FOREACH=47, FROM=48, GET=49, GOTO=50, 
		GROUP=51, IF=52, IMPLICIT=53, IN=54, INT=55, INTERFACE=56, INTERNAL=57, 
		INTO=58, IS=59, JOIN=60, LET=61, LOCK=62, LONG=63, NAMEOF=64, NAMESPACE=65, 
		NEW=66, NULL_=67, OBJECT=68, ON=69, OPERATOR=70, ORDERBY=71, OUT=72, OVERRIDE=73, 
		PARAMS=74, PARTIAL=75, PRIVATE=76, PROTECTED=77, PUBLIC=78, READONLY=79, 
		REF=80, REMOVE=81, RETURN=82, SBYTE=83, SEALED=84, SELECT=85, SET=86, 
		SHORT=87, SIZEOF=88, STACKALLOC=89, STATIC=90, STRING=91, STRUCT=92, SWITCH=93, 
		THIS=94, THROW=95, TRUE=96, TRY=97, TYPEOF=98, UINT=99, ULONG=100, UNCHECKED=101, 
		UNMANAGED=102, UNSAFE=103, USHORT=104, USING=105, VAR=106, VIRTUAL=107, 
		VOID=108, VOLATILE=109, WHEN=110, WHERE=111, WHILE=112, YIELD=113, IDENTIFIER=114, 
		LITERAL_ACCESS=115, INTEGER_LITERAL=116, HEX_INTEGER_LITERAL=117, BIN_INTEGER_LITERAL=118, 
		REAL_LITERAL=119, CHARACTER_LITERAL=120, REGULAR_STRING=121, VERBATIUM_STRING=122, 
		INTERPOLATED_REGULAR_STRING_START=123, INTERPOLATED_VERBATIUM_STRING_START=124, 
		OPEN_BRACE=125, CLOSE_BRACE=126, OPEN_BRACKET=127, CLOSE_BRACKET=128, 
		OPEN_PARENS=129, CLOSE_PARENS=130, DOT=131, COMMA=132, COLON=133, SEMICOLON=134, 
		PLUS=135, MINUS=136, STAR=137, DIV=138, PERCENT=139, AMP=140, BITWISE_OR=141, 
		CARET=142, BANG=143, TILDE=144, ASSIGNMENT=145, LT=146, GT=147, INTERR=148, 
		DOUBLE_COLON=149, OP_COALESCING=150, OP_INC=151, OP_DEC=152, OP_AND=153, 
		OP_OR=154, OP_PTR=155, OP_EQ=156, OP_NE=157, OP_LE=158, OP_GE=159, OP_ADD_ASSIGNMENT=160, 
		OP_SUB_ASSIGNMENT=161, OP_MULT_ASSIGNMENT=162, OP_DIV_ASSIGNMENT=163, 
		OP_MOD_ASSIGNMENT=164, OP_AND_ASSIGNMENT=165, OP_OR_ASSIGNMENT=166, OP_XOR_ASSIGNMENT=167, 
		OP_LEFT_SHIFT=168, OP_LEFT_SHIFT_ASSIGNMENT=169, OP_COALESCING_ASSIGNMENT=170, 
		OP_RANGE=171, DOUBLE_CURLY_INSIDE=172, OPEN_BRACE_INSIDE=173, REGULAR_CHAR_INSIDE=174, 
		VERBATIUM_DOUBLE_QUOTE_INSIDE=175, DOUBLE_QUOTE_INSIDE=176, REGULAR_STRING_INSIDE=177, 
		VERBATIUM_INSIDE_STRING=178, CLOSE_BRACE_INSIDE=179, FORMAT_STRING=180, 
		DIRECTIVE_WHITESPACES=181, DIGITS=182, DEFINE=183, UNDEF=184, ELIF=185, 
		ENDIF=186, LINE=187, ERROR=188, WARNING=189, REGION=190, ENDREGION=191, 
		PRAGMA=192, NULLABLE=193, DIRECTIVE_HIDDEN=194, CONDITIONAL_SYMBOL=195, 
		DIRECTIVE_NEW_LINE=196, TEXT=197, DOUBLE_CURLY_CLOSE_INSIDE=198;
	public static final int
		RULE_preprocessor_directive = 0, RULE_directive_new_line_or_sharp = 1, 
		RULE_preprocessor_expression = 2;
	private static String[] makeRuleNames() {
		return new String[] {
			"preprocessor_directive", "directive_new_line_or_sharp", "preprocessor_expression"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'\u00EF\u00BB\u00BF'", null, "'/***/'", null, null, null, null, 
			"'#'", "'abstract'", "'add'", "'alias'", "'__arglist'", "'as'", "'ascending'", 
			"'async'", "'await'", "'base'", "'bool'", "'break'", "'by'", "'byte'", 
			"'case'", "'catch'", "'char'", "'checked'", "'class'", "'const'", "'continue'", 
			"'decimal'", "'default'", "'delegate'", "'descending'", "'do'", "'double'", 
			"'dynamic'", "'else'", "'enum'", "'equals'", "'event'", "'explicit'", 
			"'extern'", "'false'", "'finally'", "'fixed'", "'float'", "'for'", "'foreach'", 
			"'from'", "'get'", "'goto'", "'group'", "'if'", "'implicit'", "'in'", 
			"'int'", "'interface'", "'internal'", "'into'", "'is'", "'join'", "'let'", 
			"'lock'", "'long'", "'nameof'", "'namespace'", "'new'", "'null'", "'object'", 
			"'on'", "'operator'", "'orderby'", "'out'", "'override'", "'params'", 
			"'partial'", "'private'", "'protected'", "'public'", "'readonly'", "'ref'", 
			"'remove'", "'return'", "'sbyte'", "'sealed'", "'select'", "'set'", "'short'", 
			"'sizeof'", "'stackalloc'", "'static'", "'string'", "'struct'", "'switch'", 
			"'this'", "'throw'", "'true'", "'try'", "'typeof'", "'uint'", "'ulong'", 
			"'unchecked'", "'unmanaged'", "'unsafe'", "'ushort'", "'using'", "'var'", 
			"'virtual'", "'void'", "'volatile'", "'when'", "'where'", "'while'", 
			"'yield'", null, null, null, null, null, null, null, null, null, null, 
			null, "'{'", "'}'", "'['", "']'", "'('", "')'", "'.'", "','", "':'", 
			"';'", "'+'", "'-'", "'*'", "'/'", "'%'", "'&'", "'|'", "'^'", "'!'", 
			"'~'", "'='", "'<'", "'>'", "'?'", "'::'", "'??'", "'++'", "'--'", "'&&'", 
			"'||'", "'->'", "'=='", "'!='", "'<='", "'>='", "'+='", "'-='", "'*='", 
			"'/='", "'%='", "'&='", "'|='", "'^='", "'<<'", "'<<='", "'??='", "'..'", 
			"'{{'", null, null, null, null, null, null, null, null, null, null, "'define'", 
			"'undef'", "'elif'", "'endif'", "'line'", null, null, null, null, null, 
			null, "'hidden'", null, null, null, "'}}'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "BYTE_ORDER_MARK", "SINGLE_LINE_DOC_COMMENT", "EMPTY_DELIMITED_DOC_COMMENT", 
			"DELIMITED_DOC_COMMENT", "SINGLE_LINE_COMMENT", "DELIMITED_COMMENT", 
			"WHITESPACES", "SHARP", "ABSTRACT", "ADD", "ALIAS", "ARGLIST", "AS", 
			"ASCENDING", "ASYNC", "AWAIT", "BASE", "BOOL", "BREAK", "BY", "BYTE", 
			"CASE", "CATCH", "CHAR", "CHECKED", "CLASS", "CONST", "CONTINUE", "DECIMAL", 
			"DEFAULT", "DELEGATE", "DESCENDING", "DO", "DOUBLE", "DYNAMIC", "ELSE", 
			"ENUM", "EQUALS", "EVENT", "EXPLICIT", "EXTERN", "FALSE", "FINALLY", 
			"FIXED", "FLOAT", "FOR", "FOREACH", "FROM", "GET", "GOTO", "GROUP", "IF", 
			"IMPLICIT", "IN", "INT", "INTERFACE", "INTERNAL", "INTO", "IS", "JOIN", 
			"LET", "LOCK", "LONG", "NAMEOF", "NAMESPACE", "NEW", "NULL_", "OBJECT", 
			"ON", "OPERATOR", "ORDERBY", "OUT", "OVERRIDE", "PARAMS", "PARTIAL", 
			"PRIVATE", "PROTECTED", "PUBLIC", "READONLY", "REF", "REMOVE", "RETURN", 
			"SBYTE", "SEALED", "SELECT", "SET", "SHORT", "SIZEOF", "STACKALLOC", 
			"STATIC", "STRING", "STRUCT", "SWITCH", "THIS", "THROW", "TRUE", "TRY", 
			"TYPEOF", "UINT", "ULONG", "UNCHECKED", "UNMANAGED", "UNSAFE", "USHORT", 
			"USING", "VAR", "VIRTUAL", "VOID", "VOLATILE", "WHEN", "WHERE", "WHILE", 
			"YIELD", "IDENTIFIER", "LITERAL_ACCESS", "INTEGER_LITERAL", "HEX_INTEGER_LITERAL", 
			"BIN_INTEGER_LITERAL", "REAL_LITERAL", "CHARACTER_LITERAL", "REGULAR_STRING", 
			"VERBATIUM_STRING", "INTERPOLATED_REGULAR_STRING_START", "INTERPOLATED_VERBATIUM_STRING_START", 
			"OPEN_BRACE", "CLOSE_BRACE", "OPEN_BRACKET", "CLOSE_BRACKET", "OPEN_PARENS", 
			"CLOSE_PARENS", "DOT", "COMMA", "COLON", "SEMICOLON", "PLUS", "MINUS", 
			"STAR", "DIV", "PERCENT", "AMP", "BITWISE_OR", "CARET", "BANG", "TILDE", 
			"ASSIGNMENT", "LT", "GT", "INTERR", "DOUBLE_COLON", "OP_COALESCING", 
			"OP_INC", "OP_DEC", "OP_AND", "OP_OR", "OP_PTR", "OP_EQ", "OP_NE", "OP_LE", 
			"OP_GE", "OP_ADD_ASSIGNMENT", "OP_SUB_ASSIGNMENT", "OP_MULT_ASSIGNMENT", 
			"OP_DIV_ASSIGNMENT", "OP_MOD_ASSIGNMENT", "OP_AND_ASSIGNMENT", "OP_OR_ASSIGNMENT", 
			"OP_XOR_ASSIGNMENT", "OP_LEFT_SHIFT", "OP_LEFT_SHIFT_ASSIGNMENT", "OP_COALESCING_ASSIGNMENT", 
			"OP_RANGE", "DOUBLE_CURLY_INSIDE", "OPEN_BRACE_INSIDE", "REGULAR_CHAR_INSIDE", 
			"VERBATIUM_DOUBLE_QUOTE_INSIDE", "DOUBLE_QUOTE_INSIDE", "REGULAR_STRING_INSIDE", 
			"VERBATIUM_INSIDE_STRING", "CLOSE_BRACE_INSIDE", "FORMAT_STRING", "DIRECTIVE_WHITESPACES", 
			"DIGITS", "DEFINE", "UNDEF", "ELIF", "ENDIF", "LINE", "ERROR", "WARNING", 
			"REGION", "ENDREGION", "PRAGMA", "NULLABLE", "DIRECTIVE_HIDDEN", "CONDITIONAL_SYMBOL", 
			"DIRECTIVE_NEW_LINE", "TEXT", "DOUBLE_CURLY_CLOSE_INSIDE"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "CSharpPreprocessorParser.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	Stack<Boolean> conditions = new Stack<Boolean>() {{ conditions.push(true); }};
	public HashSet<String> ConditionalSymbols = new HashSet<String>() {{ ConditionalSymbols.add("DEBUG"); }};

	private boolean allConditions() {
		for(boolean condition: conditions) {
			if (!condition)
				return false;
		}
		return true;
	}

	public CSharpPreprocessorParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class Preprocessor_directiveContext extends ParserRuleContext {
		public boolean value;
		public Preprocessor_directiveContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_preprocessor_directive; }
	 
		public Preprocessor_directiveContext() { }
		public void copyFrom(Preprocessor_directiveContext ctx) {
			super.copyFrom(ctx);
			this.value = ctx.value;
		}
	}
	public static class PreprocessorDiagnosticContext extends Preprocessor_directiveContext {
		public TerminalNode ERROR() { return getToken(CSharpPreprocessorParser.ERROR, 0); }
		public TerminalNode TEXT() { return getToken(CSharpPreprocessorParser.TEXT, 0); }
		public Directive_new_line_or_sharpContext directive_new_line_or_sharp() {
			return getRuleContext(Directive_new_line_or_sharpContext.class,0);
		}
		public TerminalNode WARNING() { return getToken(CSharpPreprocessorParser.WARNING, 0); }
		public PreprocessorDiagnosticContext(Preprocessor_directiveContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSharpPreprocessorParserListener ) ((CSharpPreprocessorParserListener)listener).enterPreprocessorDiagnostic(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSharpPreprocessorParserListener ) ((CSharpPreprocessorParserListener)listener).exitPreprocessorDiagnostic(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CSharpPreprocessorParserVisitor ) return ((CSharpPreprocessorParserVisitor<? extends T>)visitor).visitPreprocessorDiagnostic(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class PreprocessorNullableContext extends Preprocessor_directiveContext {
		public TerminalNode NULLABLE() { return getToken(CSharpPreprocessorParser.NULLABLE, 0); }
		public TerminalNode TEXT() { return getToken(CSharpPreprocessorParser.TEXT, 0); }
		public Directive_new_line_or_sharpContext directive_new_line_or_sharp() {
			return getRuleContext(Directive_new_line_or_sharpContext.class,0);
		}
		public PreprocessorNullableContext(Preprocessor_directiveContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSharpPreprocessorParserListener ) ((CSharpPreprocessorParserListener)listener).enterPreprocessorNullable(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSharpPreprocessorParserListener ) ((CSharpPreprocessorParserListener)listener).exitPreprocessorNullable(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CSharpPreprocessorParserVisitor ) return ((CSharpPreprocessorParserVisitor<? extends T>)visitor).visitPreprocessorNullable(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class PreprocessorRegionContext extends Preprocessor_directiveContext {
		public TerminalNode REGION() { return getToken(CSharpPreprocessorParser.REGION, 0); }
		public Directive_new_line_or_sharpContext directive_new_line_or_sharp() {
			return getRuleContext(Directive_new_line_or_sharpContext.class,0);
		}
		public TerminalNode TEXT() { return getToken(CSharpPreprocessorParser.TEXT, 0); }
		public TerminalNode ENDREGION() { return getToken(CSharpPreprocessorParser.ENDREGION, 0); }
		public PreprocessorRegionContext(Preprocessor_directiveContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSharpPreprocessorParserListener ) ((CSharpPreprocessorParserListener)listener).enterPreprocessorRegion(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSharpPreprocessorParserListener ) ((CSharpPreprocessorParserListener)listener).exitPreprocessorRegion(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CSharpPreprocessorParserVisitor ) return ((CSharpPreprocessorParserVisitor<? extends T>)visitor).visitPreprocessorRegion(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class PreprocessorDeclarationContext extends Preprocessor_directiveContext {
		public Token CONDITIONAL_SYMBOL;
		public TerminalNode DEFINE() { return getToken(CSharpPreprocessorParser.DEFINE, 0); }
		public TerminalNode CONDITIONAL_SYMBOL() { return getToken(CSharpPreprocessorParser.CONDITIONAL_SYMBOL, 0); }
		public Directive_new_line_or_sharpContext directive_new_line_or_sharp() {
			return getRuleContext(Directive_new_line_or_sharpContext.class,0);
		}
		public TerminalNode UNDEF() { return getToken(CSharpPreprocessorParser.UNDEF, 0); }
		public PreprocessorDeclarationContext(Preprocessor_directiveContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSharpPreprocessorParserListener ) ((CSharpPreprocessorParserListener)listener).enterPreprocessorDeclaration(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSharpPreprocessorParserListener ) ((CSharpPreprocessorParserListener)listener).exitPreprocessorDeclaration(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CSharpPreprocessorParserVisitor ) return ((CSharpPreprocessorParserVisitor<? extends T>)visitor).visitPreprocessorDeclaration(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class PreprocessorConditionalContext extends Preprocessor_directiveContext {
		public Preprocessor_expressionContext expr;
		public TerminalNode IF() { return getToken(CSharpPreprocessorParser.IF, 0); }
		public Directive_new_line_or_sharpContext directive_new_line_or_sharp() {
			return getRuleContext(Directive_new_line_or_sharpContext.class,0);
		}
		public Preprocessor_expressionContext preprocessor_expression() {
			return getRuleContext(Preprocessor_expressionContext.class,0);
		}
		public TerminalNode ELIF() { return getToken(CSharpPreprocessorParser.ELIF, 0); }
		public TerminalNode ELSE() { return getToken(CSharpPreprocessorParser.ELSE, 0); }
		public TerminalNode ENDIF() { return getToken(CSharpPreprocessorParser.ENDIF, 0); }
		public PreprocessorConditionalContext(Preprocessor_directiveContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSharpPreprocessorParserListener ) ((CSharpPreprocessorParserListener)listener).enterPreprocessorConditional(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSharpPreprocessorParserListener ) ((CSharpPreprocessorParserListener)listener).exitPreprocessorConditional(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CSharpPreprocessorParserVisitor ) return ((CSharpPreprocessorParserVisitor<? extends T>)visitor).visitPreprocessorConditional(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class PreprocessorPragmaContext extends Preprocessor_directiveContext {
		public TerminalNode PRAGMA() { return getToken(CSharpPreprocessorParser.PRAGMA, 0); }
		public TerminalNode TEXT() { return getToken(CSharpPreprocessorParser.TEXT, 0); }
		public Directive_new_line_or_sharpContext directive_new_line_or_sharp() {
			return getRuleContext(Directive_new_line_or_sharpContext.class,0);
		}
		public PreprocessorPragmaContext(Preprocessor_directiveContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSharpPreprocessorParserListener ) ((CSharpPreprocessorParserListener)listener).enterPreprocessorPragma(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSharpPreprocessorParserListener ) ((CSharpPreprocessorParserListener)listener).exitPreprocessorPragma(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CSharpPreprocessorParserVisitor ) return ((CSharpPreprocessorParserVisitor<? extends T>)visitor).visitPreprocessorPragma(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class PreprocessorLineContext extends Preprocessor_directiveContext {
		public TerminalNode LINE() { return getToken(CSharpPreprocessorParser.LINE, 0); }
		public Directive_new_line_or_sharpContext directive_new_line_or_sharp() {
			return getRuleContext(Directive_new_line_or_sharpContext.class,0);
		}
		public TerminalNode DIGITS() { return getToken(CSharpPreprocessorParser.DIGITS, 0); }
		public TerminalNode DEFAULT() { return getToken(CSharpPreprocessorParser.DEFAULT, 0); }
		public TerminalNode DIRECTIVE_HIDDEN() { return getToken(CSharpPreprocessorParser.DIRECTIVE_HIDDEN, 0); }
		public TerminalNode STRING() { return getToken(CSharpPreprocessorParser.STRING, 0); }
		public PreprocessorLineContext(Preprocessor_directiveContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSharpPreprocessorParserListener ) ((CSharpPreprocessorParserListener)listener).enterPreprocessorLine(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSharpPreprocessorParserListener ) ((CSharpPreprocessorParserListener)listener).exitPreprocessorLine(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CSharpPreprocessorParserVisitor ) return ((CSharpPreprocessorParserVisitor<? extends T>)visitor).visitPreprocessorLine(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Preprocessor_directiveContext preprocessor_directive() throws RecognitionException {
		Preprocessor_directiveContext _localctx = new Preprocessor_directiveContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_preprocessor_directive);
		int _la;
		try {
			setState(80);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case DEFINE:
				_localctx = new PreprocessorDeclarationContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(6);
				match(DEFINE);
				setState(7);
				((PreprocessorDeclarationContext)_localctx).CONDITIONAL_SYMBOL = match(CONDITIONAL_SYMBOL);
				setState(8);
				directive_new_line_or_sharp();
				 ConditionalSymbols.add((((PreprocessorDeclarationContext)_localctx).CONDITIONAL_SYMBOL!=null?((PreprocessorDeclarationContext)_localctx).CONDITIONAL_SYMBOL.getText():null));
					   ((PreprocessorDeclarationContext)_localctx).value =  allConditions(); 
				}
				break;
			case UNDEF:
				_localctx = new PreprocessorDeclarationContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(11);
				match(UNDEF);
				setState(12);
				((PreprocessorDeclarationContext)_localctx).CONDITIONAL_SYMBOL = match(CONDITIONAL_SYMBOL);
				setState(13);
				directive_new_line_or_sharp();
				 ConditionalSymbols.remove((((PreprocessorDeclarationContext)_localctx).CONDITIONAL_SYMBOL!=null?((PreprocessorDeclarationContext)_localctx).CONDITIONAL_SYMBOL.getText():null));
					   ((PreprocessorDeclarationContext)_localctx).value =  allConditions(); 
				}
				break;
			case IF:
				_localctx = new PreprocessorConditionalContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(16);
				match(IF);
				setState(17);
				((PreprocessorConditionalContext)_localctx).expr = preprocessor_expression(0);
				setState(18);
				directive_new_line_or_sharp();
				 ((PreprocessorConditionalContext)_localctx).value =  ((PreprocessorConditionalContext)_localctx).expr.value.equals("true") && allConditions(); conditions.push(((PreprocessorConditionalContext)_localctx).expr.value.equals("true")); 
				}
				break;
			case ELIF:
				_localctx = new PreprocessorConditionalContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(21);
				match(ELIF);
				setState(22);
				((PreprocessorConditionalContext)_localctx).expr = preprocessor_expression(0);
				setState(23);
				directive_new_line_or_sharp();
				 if (!conditions.peek()) { conditions.pop(); ((PreprocessorConditionalContext)_localctx).value =  ((PreprocessorConditionalContext)_localctx).expr.value.equals("true") && allConditions();
					     conditions.push(((PreprocessorConditionalContext)_localctx).expr.value.equals("true")); } else ((PreprocessorConditionalContext)_localctx).value =  false; 
				}
				break;
			case ELSE:
				_localctx = new PreprocessorConditionalContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(26);
				match(ELSE);
				setState(27);
				directive_new_line_or_sharp();
				 if (!conditions.peek()) { conditions.pop(); ((PreprocessorConditionalContext)_localctx).value =  true && allConditions(); conditions.push(true); }
					    else ((PreprocessorConditionalContext)_localctx).value =  false; 
				}
				break;
			case ENDIF:
				_localctx = new PreprocessorConditionalContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(30);
				match(ENDIF);
				setState(31);
				directive_new_line_or_sharp();
				 conditions.pop(); ((PreprocessorConditionalContext)_localctx).value =  conditions.peek(); 
				}
				break;
			case LINE:
				_localctx = new PreprocessorLineContext(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(34);
				match(LINE);
				setState(41);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case DIGITS:
					{
					setState(35);
					match(DIGITS);
					setState(37);
					_errHandler.sync(this);
					_la = _input.LA(1);
					if (_la==STRING) {
						{
						setState(36);
						match(STRING);
						}
					}

					}
					break;
				case DEFAULT:
					{
					setState(39);
					match(DEFAULT);
					}
					break;
				case DIRECTIVE_HIDDEN:
					{
					setState(40);
					match(DIRECTIVE_HIDDEN);
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(43);
				directive_new_line_or_sharp();
				 ((PreprocessorLineContext)_localctx).value =  allConditions(); 
				}
				break;
			case ERROR:
				_localctx = new PreprocessorDiagnosticContext(_localctx);
				enterOuterAlt(_localctx, 8);
				{
				setState(46);
				match(ERROR);
				setState(47);
				match(TEXT);
				setState(48);
				directive_new_line_or_sharp();
				 ((PreprocessorDiagnosticContext)_localctx).value =  allConditions(); 
				}
				break;
			case WARNING:
				_localctx = new PreprocessorDiagnosticContext(_localctx);
				enterOuterAlt(_localctx, 9);
				{
				setState(51);
				match(WARNING);
				setState(52);
				match(TEXT);
				setState(53);
				directive_new_line_or_sharp();
				 ((PreprocessorDiagnosticContext)_localctx).value =  allConditions(); 
				}
				break;
			case REGION:
				_localctx = new PreprocessorRegionContext(_localctx);
				enterOuterAlt(_localctx, 10);
				{
				setState(56);
				match(REGION);
				setState(58);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==TEXT) {
					{
					setState(57);
					match(TEXT);
					}
				}

				setState(60);
				directive_new_line_or_sharp();
				 ((PreprocessorRegionContext)_localctx).value =  allConditions(); 
				}
				break;
			case ENDREGION:
				_localctx = new PreprocessorRegionContext(_localctx);
				enterOuterAlt(_localctx, 11);
				{
				setState(63);
				match(ENDREGION);
				setState(65);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==TEXT) {
					{
					setState(64);
					match(TEXT);
					}
				}

				setState(67);
				directive_new_line_or_sharp();
				 ((PreprocessorRegionContext)_localctx).value =  allConditions(); 
				}
				break;
			case PRAGMA:
				_localctx = new PreprocessorPragmaContext(_localctx);
				enterOuterAlt(_localctx, 12);
				{
				setState(70);
				match(PRAGMA);
				setState(71);
				match(TEXT);
				setState(72);
				directive_new_line_or_sharp();
				 ((PreprocessorPragmaContext)_localctx).value =  allConditions(); 
				}
				break;
			case NULLABLE:
				_localctx = new PreprocessorNullableContext(_localctx);
				enterOuterAlt(_localctx, 13);
				{
				setState(75);
				match(NULLABLE);
				setState(76);
				match(TEXT);
				setState(77);
				directive_new_line_or_sharp();
				 ((PreprocessorNullableContext)_localctx).value =  allConditions(); 
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Directive_new_line_or_sharpContext extends ParserRuleContext {
		public TerminalNode DIRECTIVE_NEW_LINE() { return getToken(CSharpPreprocessorParser.DIRECTIVE_NEW_LINE, 0); }
		public TerminalNode EOF() { return getToken(CSharpPreprocessorParser.EOF, 0); }
		public Directive_new_line_or_sharpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_directive_new_line_or_sharp; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSharpPreprocessorParserListener ) ((CSharpPreprocessorParserListener)listener).enterDirective_new_line_or_sharp(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSharpPreprocessorParserListener ) ((CSharpPreprocessorParserListener)listener).exitDirective_new_line_or_sharp(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CSharpPreprocessorParserVisitor ) return ((CSharpPreprocessorParserVisitor<? extends T>)visitor).visitDirective_new_line_or_sharp(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Directive_new_line_or_sharpContext directive_new_line_or_sharp() throws RecognitionException {
		Directive_new_line_or_sharpContext _localctx = new Directive_new_line_or_sharpContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_directive_new_line_or_sharp);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(82);
			_la = _input.LA(1);
			if ( !(_la==EOF || _la==DIRECTIVE_NEW_LINE) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Preprocessor_expressionContext extends ParserRuleContext {
		public String value;
		public Preprocessor_expressionContext expr1;
		public Token CONDITIONAL_SYMBOL;
		public Preprocessor_expressionContext expr;
		public Preprocessor_expressionContext expr2;
		public TerminalNode TRUE() { return getToken(CSharpPreprocessorParser.TRUE, 0); }
		public TerminalNode FALSE() { return getToken(CSharpPreprocessorParser.FALSE, 0); }
		public TerminalNode CONDITIONAL_SYMBOL() { return getToken(CSharpPreprocessorParser.CONDITIONAL_SYMBOL, 0); }
		public TerminalNode OPEN_PARENS() { return getToken(CSharpPreprocessorParser.OPEN_PARENS, 0); }
		public TerminalNode CLOSE_PARENS() { return getToken(CSharpPreprocessorParser.CLOSE_PARENS, 0); }
		public List<Preprocessor_expressionContext> preprocessor_expression() {
			return getRuleContexts(Preprocessor_expressionContext.class);
		}
		public Preprocessor_expressionContext preprocessor_expression(int i) {
			return getRuleContext(Preprocessor_expressionContext.class,i);
		}
		public TerminalNode BANG() { return getToken(CSharpPreprocessorParser.BANG, 0); }
		public TerminalNode OP_EQ() { return getToken(CSharpPreprocessorParser.OP_EQ, 0); }
		public TerminalNode OP_NE() { return getToken(CSharpPreprocessorParser.OP_NE, 0); }
		public TerminalNode OP_AND() { return getToken(CSharpPreprocessorParser.OP_AND, 0); }
		public TerminalNode OP_OR() { return getToken(CSharpPreprocessorParser.OP_OR, 0); }
		public Preprocessor_expressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_preprocessor_expression; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof CSharpPreprocessorParserListener ) ((CSharpPreprocessorParserListener)listener).enterPreprocessor_expression(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof CSharpPreprocessorParserListener ) ((CSharpPreprocessorParserListener)listener).exitPreprocessor_expression(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof CSharpPreprocessorParserVisitor ) return ((CSharpPreprocessorParserVisitor<? extends T>)visitor).visitPreprocessor_expression(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Preprocessor_expressionContext preprocessor_expression() throws RecognitionException {
		return preprocessor_expression(0);
	}

	private Preprocessor_expressionContext preprocessor_expression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Preprocessor_expressionContext _localctx = new Preprocessor_expressionContext(_ctx, _parentState);
		Preprocessor_expressionContext _prevctx = _localctx;
		int _startState = 4;
		enterRecursionRule(_localctx, 4, RULE_preprocessor_expression, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(100);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case TRUE:
				{
				setState(85);
				match(TRUE);
				 ((Preprocessor_expressionContext)_localctx).value =  "true"; 
				}
				break;
			case FALSE:
				{
				setState(87);
				match(FALSE);
				 ((Preprocessor_expressionContext)_localctx).value =  "false"; 
				}
				break;
			case CONDITIONAL_SYMBOL:
				{
				setState(89);
				((Preprocessor_expressionContext)_localctx).CONDITIONAL_SYMBOL = match(CONDITIONAL_SYMBOL);
				 ((Preprocessor_expressionContext)_localctx).value =  ConditionalSymbols.contains((((Preprocessor_expressionContext)_localctx).CONDITIONAL_SYMBOL!=null?((Preprocessor_expressionContext)_localctx).CONDITIONAL_SYMBOL.getText():null)) ? "true" : "false"; 
				}
				break;
			case OPEN_PARENS:
				{
				setState(91);
				match(OPEN_PARENS);
				setState(92);
				((Preprocessor_expressionContext)_localctx).expr = preprocessor_expression(0);
				setState(93);
				match(CLOSE_PARENS);
				 ((Preprocessor_expressionContext)_localctx).value =  ((Preprocessor_expressionContext)_localctx).expr.value; 
				}
				break;
			case BANG:
				{
				setState(96);
				match(BANG);
				setState(97);
				((Preprocessor_expressionContext)_localctx).expr = preprocessor_expression(5);
				 ((Preprocessor_expressionContext)_localctx).value =  ((Preprocessor_expressionContext)_localctx).expr.value.equals("true") ? "false" : "true"; 
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(124);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,7,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(122);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
					case 1:
						{
						_localctx = new Preprocessor_expressionContext(_parentctx, _parentState);
						_localctx.expr1 = _prevctx;
						_localctx.expr1 = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_preprocessor_expression);
						setState(102);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(103);
						match(OP_EQ);
						setState(104);
						((Preprocessor_expressionContext)_localctx).expr2 = preprocessor_expression(5);
						 ((Preprocessor_expressionContext)_localctx).value =  (((Preprocessor_expressionContext)_localctx).expr1.value == ((Preprocessor_expressionContext)_localctx).expr2.value ? "true" : "false"); 
						}
						break;
					case 2:
						{
						_localctx = new Preprocessor_expressionContext(_parentctx, _parentState);
						_localctx.expr1 = _prevctx;
						_localctx.expr1 = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_preprocessor_expression);
						setState(107);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(108);
						match(OP_NE);
						setState(109);
						((Preprocessor_expressionContext)_localctx).expr2 = preprocessor_expression(4);
						 ((Preprocessor_expressionContext)_localctx).value =  (((Preprocessor_expressionContext)_localctx).expr1.value != ((Preprocessor_expressionContext)_localctx).expr2.value ? "true" : "false"); 
						}
						break;
					case 3:
						{
						_localctx = new Preprocessor_expressionContext(_parentctx, _parentState);
						_localctx.expr1 = _prevctx;
						_localctx.expr1 = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_preprocessor_expression);
						setState(112);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(113);
						match(OP_AND);
						setState(114);
						((Preprocessor_expressionContext)_localctx).expr2 = preprocessor_expression(3);
						 ((Preprocessor_expressionContext)_localctx).value =  (((Preprocessor_expressionContext)_localctx).expr1.value.equals("true") && ((Preprocessor_expressionContext)_localctx).expr2.value.equals("true") ? "true" : "false"); 
						}
						break;
					case 4:
						{
						_localctx = new Preprocessor_expressionContext(_parentctx, _parentState);
						_localctx.expr1 = _prevctx;
						_localctx.expr1 = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_preprocessor_expression);
						setState(117);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(118);
						match(OP_OR);
						setState(119);
						((Preprocessor_expressionContext)_localctx).expr2 = preprocessor_expression(2);
						 ((Preprocessor_expressionContext)_localctx).value =  (((Preprocessor_expressionContext)_localctx).expr1.value.equals("true") || ((Preprocessor_expressionContext)_localctx).expr2.value.equals("true") ? "true" : "false"); 
						}
						break;
					}
					} 
				}
				setState(126);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,7,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 2:
			return preprocessor_expression_sempred((Preprocessor_expressionContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean preprocessor_expression_sempred(Preprocessor_expressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 4);
		case 1:
			return precpred(_ctx, 3);
		case 2:
			return precpred(_ctx, 2);
		case 3:
			return precpred(_ctx, 1);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\u00c8\u0082\4\2\t"+
		"\2\4\3\t\3\4\4\t\4\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2"+
		"\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3"+
		"\2\5\2(\n\2\3\2\3\2\5\2,\n\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3"+
		"\2\3\2\3\2\3\2\3\2\5\2=\n\2\3\2\3\2\3\2\3\2\3\2\5\2D\n\2\3\2\3\2\3\2\3"+
		"\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\5\2S\n\2\3\3\3\3\3\4\3\4\3\4\3"+
		"\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\5\4g\n\4\3\4\3\4\3"+
		"\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4"+
		"\7\4}\n\4\f\4\16\4\u0080\13\4\3\4\2\3\6\5\2\4\6\2\3\3\3\u00c6\u00c6\2"+
		"\u0097\2R\3\2\2\2\4T\3\2\2\2\6f\3\2\2\2\b\t\7\u00b9\2\2\t\n\7\u00c5\2"+
		"\2\n\13\5\4\3\2\13\f\b\2\1\2\fS\3\2\2\2\r\16\7\u00ba\2\2\16\17\7\u00c5"+
		"\2\2\17\20\5\4\3\2\20\21\b\2\1\2\21S\3\2\2\2\22\23\7\66\2\2\23\24\5\6"+
		"\4\2\24\25\5\4\3\2\25\26\b\2\1\2\26S\3\2\2\2\27\30\7\u00bb\2\2\30\31\5"+
		"\6\4\2\31\32\5\4\3\2\32\33\b\2\1\2\33S\3\2\2\2\34\35\7&\2\2\35\36\5\4"+
		"\3\2\36\37\b\2\1\2\37S\3\2\2\2 !\7\u00bc\2\2!\"\5\4\3\2\"#\b\2\1\2#S\3"+
		"\2\2\2$+\7\u00bd\2\2%\'\7\u00b8\2\2&(\7]\2\2\'&\3\2\2\2\'(\3\2\2\2(,\3"+
		"\2\2\2),\7 \2\2*,\7\u00c4\2\2+%\3\2\2\2+)\3\2\2\2+*\3\2\2\2,-\3\2\2\2"+
		"-.\5\4\3\2./\b\2\1\2/S\3\2\2\2\60\61\7\u00be\2\2\61\62\7\u00c7\2\2\62"+
		"\63\5\4\3\2\63\64\b\2\1\2\64S\3\2\2\2\65\66\7\u00bf\2\2\66\67\7\u00c7"+
		"\2\2\678\5\4\3\289\b\2\1\29S\3\2\2\2:<\7\u00c0\2\2;=\7\u00c7\2\2<;\3\2"+
		"\2\2<=\3\2\2\2=>\3\2\2\2>?\5\4\3\2?@\b\2\1\2@S\3\2\2\2AC\7\u00c1\2\2B"+
		"D\7\u00c7\2\2CB\3\2\2\2CD\3\2\2\2DE\3\2\2\2EF\5\4\3\2FG\b\2\1\2GS\3\2"+
		"\2\2HI\7\u00c2\2\2IJ\7\u00c7\2\2JK\5\4\3\2KL\b\2\1\2LS\3\2\2\2MN\7\u00c3"+
		"\2\2NO\7\u00c7\2\2OP\5\4\3\2PQ\b\2\1\2QS\3\2\2\2R\b\3\2\2\2R\r\3\2\2\2"+
		"R\22\3\2\2\2R\27\3\2\2\2R\34\3\2\2\2R \3\2\2\2R$\3\2\2\2R\60\3\2\2\2R"+
		"\65\3\2\2\2R:\3\2\2\2RA\3\2\2\2RH\3\2\2\2RM\3\2\2\2S\3\3\2\2\2TU\t\2\2"+
		"\2U\5\3\2\2\2VW\b\4\1\2WX\7b\2\2Xg\b\4\1\2YZ\7,\2\2Zg\b\4\1\2[\\\7\u00c5"+
		"\2\2\\g\b\4\1\2]^\7\u0083\2\2^_\5\6\4\2_`\7\u0084\2\2`a\b\4\1\2ag\3\2"+
		"\2\2bc\7\u0091\2\2cd\5\6\4\7de\b\4\1\2eg\3\2\2\2fV\3\2\2\2fY\3\2\2\2f"+
		"[\3\2\2\2f]\3\2\2\2fb\3\2\2\2g~\3\2\2\2hi\f\6\2\2ij\7\u009e\2\2jk\5\6"+
		"\4\7kl\b\4\1\2l}\3\2\2\2mn\f\5\2\2no\7\u009f\2\2op\5\6\4\6pq\b\4\1\2q"+
		"}\3\2\2\2rs\f\4\2\2st\7\u009b\2\2tu\5\6\4\5uv\b\4\1\2v}\3\2\2\2wx\f\3"+
		"\2\2xy\7\u009c\2\2yz\5\6\4\4z{\b\4\1\2{}\3\2\2\2|h\3\2\2\2|m\3\2\2\2|"+
		"r\3\2\2\2|w\3\2\2\2}\u0080\3\2\2\2~|\3\2\2\2~\177\3\2\2\2\177\7\3\2\2"+
		"\2\u0080~\3\2\2\2\n\'+<CRf|~";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}