// Generated from C:/Users/kwnaf/IdeaProjects/antlrTesting\PythonLexer.g4 by ANTLR 4.9.2
package PythonParser;
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class PythonLexer extends PythonLexerBase {
	static { RuntimeMetaData.checkVersion("4.9.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		INDENT=1, DEDENT=2, LINE_BREAK=3, DEF=4, RETURN=5, RAISE=6, FROM=7, IMPORT=8, 
		NONLOCAL=9, AS=10, GLOBAL=11, ASSERT=12, IF=13, ELIF=14, ELSE=15, WHILE=16, 
		FOR=17, IN=18, TRY=19, NONE=20, FINALLY=21, WITH=22, EXCEPT=23, LAMBDA=24, 
		OR=25, AND=26, NOT=27, IS=28, CLASS=29, YIELD=30, DEL=31, PASS=32, CONTINUE=33, 
		BREAK=34, ASYNC=35, AWAIT=36, PRINT=37, EXEC=38, TRUE=39, FALSE=40, SWITCH=41, 
		CASE=42, DEFAULT=43, DOT=44, ELLIPSIS=45, REVERSE_QUOTE=46, STAR=47, COMMA=48, 
		COLON=49, SEMI_COLON=50, POWER=51, ASSIGN=52, OR_OP=53, XOR=54, AND_OP=55, 
		LEFT_SHIFT=56, RIGHT_SHIFT=57, ADD=58, MINUS=59, DIV=60, MOD=61, IDIV=62, 
		NOT_OP=63, LESS_THAN=64, GREATER_THAN=65, EQUALS=66, GT_EQ=67, LT_EQ=68, 
		NOT_EQ_1=69, NOT_EQ_2=70, AT=71, ARROW=72, ADD_ASSIGN=73, SUB_ASSIGN=74, 
		MULT_ASSIGN=75, AT_ASSIGN=76, DIV_ASSIGN=77, MOD_ASSIGN=78, AND_ASSIGN=79, 
		OR_ASSIGN=80, XOR_ASSIGN=81, LEFT_SHIFT_ASSIGN=82, RIGHT_SHIFT_ASSIGN=83, 
		POWER_ASSIGN=84, IDIV_ASSIGN=85, STRING=86, DECIMAL_INTEGER=87, OCT_INTEGER=88, 
		HEX_INTEGER=89, BIN_INTEGER=90, IMAG_NUMBER=91, FLOAT_NUMBER=92, OPEN_PAREN=93, 
		CLOSE_PAREN=94, OPEN_BRACE=95, CLOSE_BRACE=96, OPEN_BRACKET=97, CLOSE_BRACKET=98, 
		NAME=99, LINE_JOIN=100, NEWLINE=101, WS=102, COMMENT=103;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"DEF", "RETURN", "RAISE", "FROM", "IMPORT", "NONLOCAL", "AS", "GLOBAL", 
			"ASSERT", "IF", "ELIF", "ELSE", "WHILE", "FOR", "IN", "TRY", "NONE", 
			"FINALLY", "WITH", "EXCEPT", "LAMBDA", "OR", "AND", "NOT", "IS", "CLASS", 
			"YIELD", "DEL", "PASS", "CONTINUE", "BREAK", "ASYNC", "AWAIT", "PRINT", 
			"EXEC", "TRUE", "FALSE", "SWITCH", "CASE", "DEFAULT", "DOT", "ELLIPSIS", 
			"REVERSE_QUOTE", "STAR", "COMMA", "COLON", "SEMI_COLON", "POWER", "ASSIGN", 
			"OR_OP", "XOR", "AND_OP", "LEFT_SHIFT", "RIGHT_SHIFT", "ADD", "MINUS", 
			"DIV", "MOD", "IDIV", "NOT_OP", "LESS_THAN", "GREATER_THAN", "EQUALS", 
			"GT_EQ", "LT_EQ", "NOT_EQ_1", "NOT_EQ_2", "AT", "ARROW", "ADD_ASSIGN", 
			"SUB_ASSIGN", "MULT_ASSIGN", "AT_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", 
			"AND_ASSIGN", "OR_ASSIGN", "XOR_ASSIGN", "LEFT_SHIFT_ASSIGN", "RIGHT_SHIFT_ASSIGN", 
			"POWER_ASSIGN", "IDIV_ASSIGN", "STRING", "DECIMAL_INTEGER", "OCT_INTEGER", 
			"HEX_INTEGER", "BIN_INTEGER", "IMAG_NUMBER", "FLOAT_NUMBER", "OPEN_PAREN", 
			"CLOSE_PAREN", "OPEN_BRACE", "CLOSE_BRACE", "OPEN_BRACKET", "CLOSE_BRACKET", 
			"NAME", "LINE_JOIN", "NEWLINE", "WS", "COMMENT", "SHORT_STRING", "LONG_STRING", 
			"LONG_STRING_ITEM", "RN", "EXPONENT_OR_POINT_FLOAT", "POINT_FLOAT", "SHORT_BYTES", 
			"LONG_BYTES", "LONG_BYTES_ITEM", "SHORT_BYTES_CHAR_NO_SINGLE_QUOTE", 
			"SHORT_BYTES_CHAR_NO_DOUBLE_QUOTE", "LONG_BYTES_CHAR", "BYTES_ESCAPE_SEQ", 
			"ID_CONTINUE", "ID_START"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, null, "'def'", "'return'", "'raise'", "'from'", "'import'", 
			"'nonlocal'", "'as'", "'global'", "'assert'", "'if'", "'elif'", "'else'", 
			"'while'", "'for'", "'in'", "'try'", "'None'", "'finally'", "'with'", 
			"'except'", "'lambda'", "'or'", "'and'", "'not'", "'is'", "'class'", 
			"'yield'", "'del'", "'pass'", "'continue'", "'break'", "'async'", "'await'", 
			"'print'", "'exec'", "'True'", "'False'", "'switch'", "'case'", "'default'", 
			"'.'", "'...'", "'`'", "'*'", "','", "':'", "';'", "'**'", "'='", "'|'", 
			"'^'", "'&'", "'<<'", "'>>'", "'+'", "'-'", "'/'", "'%'", "'//'", "'~'", 
			"'<'", "'>'", "'=='", "'>='", "'<='", "'<>'", "'!='", "'@'", "'->'", 
			"'+='", "'-='", "'*='", "'@='", "'/='", "'%='", "'&='", "'|='", "'^='", 
			"'<<='", "'>>='", "'**='", "'//='", null, null, null, null, null, null, 
			null, "'('", "')'", "'{'", "'}'", "'['", "']'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "INDENT", "DEDENT", "LINE_BREAK", "DEF", "RETURN", "RAISE", "FROM", 
			"IMPORT", "NONLOCAL", "AS", "GLOBAL", "ASSERT", "IF", "ELIF", "ELSE", 
			"WHILE", "FOR", "IN", "TRY", "NONE", "FINALLY", "WITH", "EXCEPT", "LAMBDA", 
			"OR", "AND", "NOT", "IS", "CLASS", "YIELD", "DEL", "PASS", "CONTINUE", 
			"BREAK", "ASYNC", "AWAIT", "PRINT", "EXEC", "TRUE", "FALSE", "SWITCH", 
			"CASE", "DEFAULT", "DOT", "ELLIPSIS", "REVERSE_QUOTE", "STAR", "COMMA", 
			"COLON", "SEMI_COLON", "POWER", "ASSIGN", "OR_OP", "XOR", "AND_OP", "LEFT_SHIFT", 
			"RIGHT_SHIFT", "ADD", "MINUS", "DIV", "MOD", "IDIV", "NOT_OP", "LESS_THAN", 
			"GREATER_THAN", "EQUALS", "GT_EQ", "LT_EQ", "NOT_EQ_1", "NOT_EQ_2", "AT", 
			"ARROW", "ADD_ASSIGN", "SUB_ASSIGN", "MULT_ASSIGN", "AT_ASSIGN", "DIV_ASSIGN", 
			"MOD_ASSIGN", "AND_ASSIGN", "OR_ASSIGN", "XOR_ASSIGN", "LEFT_SHIFT_ASSIGN", 
			"RIGHT_SHIFT_ASSIGN", "POWER_ASSIGN", "IDIV_ASSIGN", "STRING", "DECIMAL_INTEGER", 
			"OCT_INTEGER", "HEX_INTEGER", "BIN_INTEGER", "IMAG_NUMBER", "FLOAT_NUMBER", 
			"OPEN_PAREN", "CLOSE_PAREN", "OPEN_BRACE", "CLOSE_BRACE", "OPEN_BRACKET", 
			"CLOSE_BRACKET", "NAME", "LINE_JOIN", "NEWLINE", "WS", "COMMENT"
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


	public PythonLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "PythonLexer.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	@Override
	public void action(RuleContext _localctx, int ruleIndex, int actionIndex) {
		switch (ruleIndex) {
		case 89:
			OPEN_PAREN_action((RuleContext)_localctx, actionIndex);
			break;
		case 90:
			CLOSE_PAREN_action((RuleContext)_localctx, actionIndex);
			break;
		case 91:
			OPEN_BRACE_action((RuleContext)_localctx, actionIndex);
			break;
		case 92:
			CLOSE_BRACE_action((RuleContext)_localctx, actionIndex);
			break;
		case 93:
			OPEN_BRACKET_action((RuleContext)_localctx, actionIndex);
			break;
		case 94:
			CLOSE_BRACKET_action((RuleContext)_localctx, actionIndex);
			break;
		case 97:
			NEWLINE_action((RuleContext)_localctx, actionIndex);
			break;
		case 98:
			WS_action((RuleContext)_localctx, actionIndex);
			break;
		}
	}
	private void OPEN_PAREN_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 0:
			IncIndentLevel();
			break;
		}
	}
	private void CLOSE_PAREN_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 1:
			DecIndentLevel();
			break;
		}
	}
	private void OPEN_BRACE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 2:
			IncIndentLevel();
			break;
		}
	}
	private void CLOSE_BRACE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 3:
			DecIndentLevel();
			break;
		}
	}
	private void OPEN_BRACKET_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 4:
			IncIndentLevel();
			break;
		}
	}
	private void CLOSE_BRACKET_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 5:
			DecIndentLevel();
			break;
		}
	}
	private void NEWLINE_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 6:
			HandleNewLine();
			break;
		}
	}
	private void WS_action(RuleContext _localctx, int actionIndex) {
		switch (actionIndex) {
		case 7:
			HandleSpaces();
			break;
		}
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2i\u0372\b\1\4\2\t"+
		"\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t \4!"+
		"\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\4)\t)\4*\t*\4+\t+\4"+
		",\t,\4-\t-\4.\t.\4/\t/\4\60\t\60\4\61\t\61\4\62\t\62\4\63\t\63\4\64\t"+
		"\64\4\65\t\65\4\66\t\66\4\67\t\67\48\t8\49\t9\4:\t:\4;\t;\4<\t<\4=\t="+
		"\4>\t>\4?\t?\4@\t@\4A\tA\4B\tB\4C\tC\4D\tD\4E\tE\4F\tF\4G\tG\4H\tH\4I"+
		"\tI\4J\tJ\4K\tK\4L\tL\4M\tM\4N\tN\4O\tO\4P\tP\4Q\tQ\4R\tR\4S\tS\4T\tT"+
		"\4U\tU\4V\tV\4W\tW\4X\tX\4Y\tY\4Z\tZ\4[\t[\4\\\t\\\4]\t]\4^\t^\4_\t_\4"+
		"`\t`\4a\ta\4b\tb\4c\tc\4d\td\4e\te\4f\tf\4g\tg\4h\th\4i\ti\4j\tj\4k\t"+
		"k\4l\tl\4m\tm\4n\tn\4o\to\4p\tp\4q\tq\4r\tr\4s\ts\4t\tt\3\2\3\2\3\2\3"+
		"\2\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\4\3\4\3\4\3\4\3\4\3\4\3\5\3\5\3\5\3\5"+
		"\3\5\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3"+
		"\b\3\b\3\b\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3\13"+
		"\3\13\3\13\3\f\3\f\3\f\3\f\3\f\3\r\3\r\3\r\3\r\3\r\3\16\3\16\3\16\3\16"+
		"\3\16\3\16\3\17\3\17\3\17\3\17\3\20\3\20\3\20\3\21\3\21\3\21\3\21\3\22"+
		"\3\22\3\22\3\22\3\22\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\24\3\24"+
		"\3\24\3\24\3\24\3\25\3\25\3\25\3\25\3\25\3\25\3\25\3\26\3\26\3\26\3\26"+
		"\3\26\3\26\3\26\3\27\3\27\3\27\3\30\3\30\3\30\3\30\3\31\3\31\3\31\3\31"+
		"\3\32\3\32\3\32\3\33\3\33\3\33\3\33\3\33\3\33\3\34\3\34\3\34\3\34\3\34"+
		"\3\34\3\35\3\35\3\35\3\35\3\36\3\36\3\36\3\36\3\36\3\37\3\37\3\37\3\37"+
		"\3\37\3\37\3\37\3\37\3\37\3 \3 \3 \3 \3 \3 \3!\3!\3!\3!\3!\3!\3\"\3\""+
		"\3\"\3\"\3\"\3\"\3#\3#\3#\3#\3#\3#\3$\3$\3$\3$\3$\3%\3%\3%\3%\3%\3&\3"+
		"&\3&\3&\3&\3&\3\'\3\'\3\'\3\'\3\'\3\'\3\'\3(\3(\3(\3(\3(\3)\3)\3)\3)\3"+
		")\3)\3)\3)\3*\3*\3+\3+\3+\3+\3,\3,\3-\3-\3.\3.\3/\3/\3\60\3\60\3\61\3"+
		"\61\3\61\3\62\3\62\3\63\3\63\3\64\3\64\3\65\3\65\3\66\3\66\3\66\3\67\3"+
		"\67\3\67\38\38\39\39\3:\3:\3;\3;\3<\3<\3<\3=\3=\3>\3>\3?\3?\3@\3@\3@\3"+
		"A\3A\3A\3B\3B\3B\3C\3C\3C\3D\3D\3D\3E\3E\3F\3F\3F\3G\3G\3G\3H\3H\3H\3"+
		"I\3I\3I\3J\3J\3J\3K\3K\3K\3L\3L\3L\3M\3M\3M\3N\3N\3N\3O\3O\3O\3P\3P\3"+
		"P\3P\3Q\3Q\3Q\3Q\3R\3R\3R\3R\3S\3S\3S\3S\3T\3T\3T\5T\u023b\nT\3T\3T\5"+
		"T\u023f\nT\5T\u0241\nT\3T\3T\5T\u0245\nT\3T\3T\5T\u0249\nT\3T\3T\5T\u024d"+
		"\nT\3T\3T\5T\u0251\nT\5T\u0253\nT\3U\3U\7U\u0257\nU\fU\16U\u025a\13U\3"+
		"U\6U\u025d\nU\rU\16U\u025e\5U\u0261\nU\3V\3V\3V\6V\u0266\nV\rV\16V\u0267"+
		"\3W\3W\3W\6W\u026d\nW\rW\16W\u026e\3X\3X\3X\6X\u0274\nX\rX\16X\u0275\3"+
		"Y\3Y\6Y\u027a\nY\rY\16Y\u027b\5Y\u027e\nY\3Y\3Y\3Z\3Z\3[\3[\3[\3\\\3\\"+
		"\3\\\3]\3]\3]\3^\3^\3^\3_\3_\3_\3`\3`\3`\3a\3a\7a\u0298\na\fa\16a\u029b"+
		"\13a\3b\3b\7b\u029f\nb\fb\16b\u02a2\13b\3b\3b\3b\3b\3c\3c\3c\3c\3c\3d"+
		"\6d\u02ae\nd\rd\16d\u02af\3d\3d\3d\3d\3e\3e\7e\u02b8\ne\fe\16e\u02bb\13"+
		"e\3e\3e\3f\3f\3f\3f\5f\u02c3\nf\3f\7f\u02c6\nf\ff\16f\u02c9\13f\3f\3f"+
		"\3f\3f\3f\5f\u02d0\nf\3f\7f\u02d3\nf\ff\16f\u02d6\13f\3f\5f\u02d9\nf\3"+
		"g\3g\3g\3g\3g\7g\u02e0\ng\fg\16g\u02e3\13g\3g\3g\3g\3g\3g\3g\3g\3g\7g"+
		"\u02ed\ng\fg\16g\u02f0\13g\3g\3g\3g\5g\u02f5\ng\3h\3h\3h\3h\5h\u02fb\n"+
		"h\5h\u02fd\nh\3i\5i\u0300\ni\3i\3i\3j\6j\u0305\nj\rj\16j\u0306\3j\5j\u030a"+
		"\nj\3j\3j\5j\u030e\nj\3j\6j\u0311\nj\rj\16j\u0312\3j\5j\u0316\nj\3k\7"+
		"k\u0319\nk\fk\16k\u031c\13k\3k\3k\6k\u0320\nk\rk\16k\u0321\3k\6k\u0325"+
		"\nk\rk\16k\u0326\3k\5k\u032a\nk\3l\3l\3l\7l\u032f\nl\fl\16l\u0332\13l"+
		"\3l\3l\3l\3l\7l\u0338\nl\fl\16l\u033b\13l\3l\5l\u033e\nl\3m\3m\3m\3m\3"+
		"m\7m\u0345\nm\fm\16m\u0348\13m\3m\3m\3m\3m\3m\3m\3m\3m\7m\u0352\nm\fm"+
		"\16m\u0355\13m\3m\3m\3m\5m\u035a\nm\3n\3n\5n\u035e\nn\3o\5o\u0361\no\3"+
		"p\5p\u0364\np\3q\5q\u0367\nq\3r\3r\3r\3s\3s\5s\u036e\ns\3t\5t\u0371\n"+
		"t\6\u02e1\u02ee\u0346\u0353\2u\3\6\5\7\7\b\t\t\13\n\r\13\17\f\21\r\23"+
		"\16\25\17\27\20\31\21\33\22\35\23\37\24!\25#\26%\27\'\30)\31+\32-\33/"+
		"\34\61\35\63\36\65\37\67 9!;\"=#?$A%C&E\'G(I)K*M+O,Q-S.U/W\60Y\61[\62"+
		"]\63_\64a\65c\66e\67g8i9k:m;o<q=s>u?w@yA{B}C\177D\u0081E\u0083F\u0085"+
		"G\u0087H\u0089I\u008bJ\u008dK\u008fL\u0091M\u0093N\u0095O\u0097P\u0099"+
		"Q\u009bR\u009dS\u009fT\u00a1U\u00a3V\u00a5W\u00a7X\u00a9Y\u00abZ\u00ad"+
		"[\u00af\\\u00b1]\u00b3^\u00b5_\u00b7`\u00b9a\u00bbb\u00bdc\u00bfd\u00c1"+
		"e\u00c3f\u00c5g\u00c7h\u00c9i\u00cb\2\u00cd\2\u00cf\2\u00d1\2\u00d3\2"+
		"\u00d5\2\u00d7\2\u00d9\2\u00db\2\u00dd\2\u00df\2\u00e1\2\u00e3\2\u00e5"+
		"\2\u00e7\2\3\2\33\4\2WWww\4\2HHhh\4\2TTtt\4\2DDdd\3\2\63;\3\2\62;\4\2"+
		"QQqq\3\2\629\4\2ZZzz\5\2\62;CHch\3\2\62\63\4\2LLll\4\2\13\13\"\"\4\2\f"+
		"\f\16\17\6\2\f\f\17\17))^^\6\2\f\f\17\17$$^^\3\2^^\4\2GGgg\4\2--//\7\2"+
		"\2\13\r\16\20(*]_\u0081\7\2\2\13\r\16\20#%]_\u0081\4\2\2]_\u0081\3\2\2"+
		"\u0081\u0096\2\62;\u0302\u0371\u0485\u0488\u0593\u05bb\u05bd\u05bf\u05c1"+
		"\u05c1\u05c3\u05c4\u05c6\u05c7\u05c9\u05c9\u0612\u0617\u064d\u0660\u0662"+
		"\u066b\u0672\u0672\u06d8\u06de\u06e1\u06e6\u06e9\u06ea\u06ec\u06ef\u06f2"+
		"\u06fb\u0713\u0713\u0732\u074c\u07a8\u07b2\u0903\u0905\u093e\u093e\u0940"+
		"\u094f\u0953\u0956\u0964\u0965\u0968\u0971\u0983\u0985\u09be\u09be\u09c0"+
		"\u09c6\u09c9\u09ca\u09cd\u09cf\u09d9\u09d9\u09e4\u09e5\u09e8\u09f1\u0a03"+
		"\u0a05\u0a3e\u0a3e\u0a40\u0a44\u0a49\u0a4a\u0a4d\u0a4f\u0a68\u0a73\u0a83"+
		"\u0a85\u0abe\u0abe\u0ac0\u0ac7\u0ac9\u0acb\u0acd\u0acf\u0ae4\u0ae5\u0ae8"+
		"\u0af1\u0b03\u0b05\u0b3e\u0b3e\u0b40\u0b45\u0b49\u0b4a\u0b4d\u0b4f\u0b58"+
		"\u0b59\u0b68\u0b71\u0b84\u0b84\u0bc0\u0bc4\u0bc8\u0bca\u0bcc\u0bcf\u0bd9"+
		"\u0bd9\u0be8\u0bf1\u0c03\u0c05\u0c40\u0c46\u0c48\u0c4a\u0c4c\u0c4f\u0c57"+
		"\u0c58\u0c68\u0c71\u0c84\u0c85\u0cbe\u0cbe\u0cc0\u0cc6\u0cc8\u0cca\u0ccc"+
		"\u0ccf\u0cd7\u0cd8\u0ce8\u0cf1\u0d04\u0d05\u0d40\u0d45\u0d48\u0d4a\u0d4c"+
		"\u0d4f\u0d59\u0d59\u0d68\u0d71\u0d84\u0d85\u0dcc\u0dcc\u0dd1\u0dd6\u0dd8"+
		"\u0dd8\u0dda\u0de1\u0df4\u0df5\u0e33\u0e33\u0e36\u0e3c\u0e49\u0e50\u0e52"+
		"\u0e5b\u0eb3\u0eb3\u0eb6\u0ebb\u0ebd\u0ebe\u0eca\u0ecf\u0ed2\u0edb\u0f1a"+
		"\u0f1b\u0f22\u0f2b\u0f37\u0f37\u0f39\u0f39\u0f3b\u0f3b\u0f40\u0f41\u0f73"+
		"\u0f86\u0f88\u0f89\u0f92\u0f99\u0f9b\u0fbe\u0fc8\u0fc8\u102e\u1034\u1038"+
		"\u103b\u1042\u104b\u1058\u105b\u1361\u1361\u136b\u1373\u1714\u1716\u1734"+
		"\u1736\u1754\u1755\u1774\u1775\u17b8\u17d5\u17df\u17df\u17e2\u17eb\u180d"+
		"\u180f\u1812\u181b\u18ab\u18ab\u1922\u192d\u1932\u193d\u1948\u1951\u19b2"+
		"\u19c2\u19ca\u19cb\u19d2\u19db\u1a19\u1a1d\u1dc2\u1dc5\u2041\u2042\u2056"+
		"\u2056\u20d2\u20de\u20e3\u20e3\u20e7\u20ed\u302c\u3031\u309b\u309c\ua804"+
		"\ua804\ua808\ua808\ua80d\ua80d\ua825\ua829\ufb20\ufb20\ufe02\ufe11\ufe22"+
		"\ufe25\ufe35\ufe36\ufe4f\ufe51\uff12\uff1b\uff41\uff41\u0129\2C\\aac|"+
		"\u00ac\u00ac\u00b7\u00b7\u00bc\u00bc\u00c2\u00d8\u00da\u00f8\u00fa\u0243"+
		"\u0252\u02c3\u02c8\u02d3\u02e2\u02e6\u02f0\u02f0\u037c\u037c\u0388\u0388"+
		"\u038a\u038c\u038e\u038e\u0390\u03a3\u03a5\u03d0\u03d2\u03f7\u03f9\u0483"+
		"\u048c\u04d0\u04d2\u04fb\u0502\u0511\u0533\u0558\u055b\u055b\u0563\u0589"+
		"\u05d2\u05ec\u05f2\u05f4\u0623\u063c\u0642\u064c\u0670\u0671\u0673\u06d5"+
		"\u06d7\u06d7\u06e7\u06e8\u06f0\u06f1\u06fc\u06fe\u0701\u0701\u0712\u0712"+
		"\u0714\u0731\u074f\u076f\u0782\u07a7\u07b3\u07b3\u0906\u093b\u093f\u093f"+
		"\u0952\u0952\u095a\u0963\u097f\u097f\u0987\u098e\u0991\u0992\u0995\u09aa"+
		"\u09ac\u09b2\u09b4\u09b4\u09b8\u09bb\u09bf\u09bf\u09d0\u09d0\u09de\u09df"+
		"\u09e1\u09e3\u09f2\u09f3\u0a07\u0a0c\u0a11\u0a12\u0a15\u0a2a\u0a2c\u0a32"+
		"\u0a34\u0a35\u0a37\u0a38\u0a3a\u0a3b\u0a5b\u0a5e\u0a60\u0a60\u0a74\u0a76"+
		"\u0a87\u0a8f\u0a91\u0a93\u0a95\u0aaa\u0aac\u0ab2\u0ab4\u0ab5\u0ab7\u0abb"+
		"\u0abf\u0abf\u0ad2\u0ad2\u0ae2\u0ae3\u0b07\u0b0e\u0b11\u0b12\u0b15\u0b2a"+
		"\u0b2c\u0b32\u0b34\u0b35\u0b37\u0b3b\u0b3f\u0b3f\u0b5e\u0b5f\u0b61\u0b63"+
		"\u0b73\u0b73\u0b85\u0b85\u0b87\u0b8c\u0b90\u0b92\u0b94\u0b97\u0b9b\u0b9c"+
		"\u0b9e\u0b9e\u0ba0\u0ba1\u0ba5\u0ba6\u0baa\u0bac\u0bb0\u0bbb\u0c07\u0c0e"+
		"\u0c10\u0c12\u0c14\u0c2a\u0c2c\u0c35\u0c37\u0c3b\u0c62\u0c63\u0c87\u0c8e"+
		"\u0c90\u0c92\u0c94\u0caa\u0cac\u0cb5\u0cb7\u0cbb\u0cbf\u0cbf\u0ce0\u0ce0"+
		"\u0ce2\u0ce3\u0d07\u0d0e\u0d10\u0d12\u0d14\u0d2a\u0d2c\u0d3b\u0d62\u0d63"+
		"\u0d87\u0d98\u0d9c\u0db3\u0db5\u0dbd\u0dbf\u0dbf\u0dc2\u0dc8\u0e03\u0e32"+
		"\u0e34\u0e35\u0e42\u0e48\u0e83\u0e84\u0e86\u0e86\u0e89\u0e8a\u0e8c\u0e8c"+
		"\u0e8f\u0e8f\u0e96\u0e99\u0e9b\u0ea1\u0ea3\u0ea5\u0ea7\u0ea7\u0ea9\u0ea9"+
		"\u0eac\u0ead\u0eaf\u0eb2\u0eb4\u0eb5\u0ebf\u0ebf\u0ec2\u0ec6\u0ec8\u0ec8"+
		"\u0ede\u0edf\u0f02\u0f02\u0f42\u0f49\u0f4b\u0f6c\u0f8a\u0f8d\u1002\u1023"+
		"\u1025\u1029\u102b\u102c\u1052\u1057\u10a2\u10c7\u10d2\u10fc\u10fe\u10fe"+
		"\u1102\u115b\u1161\u11a4\u11aa\u11fb\u1202\u124a\u124c\u124f\u1252\u1258"+
		"\u125a\u125a\u125c\u125f\u1262\u128a\u128c\u128f\u1292\u12b2\u12b4\u12b7"+
		"\u12ba\u12c0\u12c2\u12c2\u12c4\u12c7\u12ca\u12d8\u12da\u1312\u1314\u1317"+
		"\u131a\u135c\u1382\u1391\u13a2\u13f6\u1403\u166e\u1671\u1678\u1683\u169c"+
		"\u16a2\u16ec\u16f0\u16f2\u1702\u170e\u1710\u1713\u1722\u1733\u1742\u1753"+
		"\u1762\u176e\u1770\u1772\u1782\u17b5\u17d9\u17d9\u17de\u17de\u1822\u1879"+
		"\u1882\u18aa\u1902\u191e\u1952\u196f\u1972\u1976\u1982\u19ab\u19c3\u19c9"+
		"\u1a02\u1a18\u1d02\u1dc1\u1e02\u1e9d\u1ea2\u1efb\u1f02\u1f17\u1f1a\u1f1f"+
		"\u1f22\u1f47\u1f4a\u1f4f\u1f52\u1f59\u1f5b\u1f5b\u1f5d\u1f5d\u1f5f\u1f5f"+
		"\u1f61\u1f7f\u1f82\u1fb6\u1fb8\u1fbe\u1fc0\u1fc0\u1fc4\u1fc6\u1fc8\u1fce"+
		"\u1fd2\u1fd5\u1fd8\u1fdd\u1fe2\u1fee\u1ff4\u1ff6\u1ff8\u1ffe\u2073\u2073"+
		"\u2081\u2081\u2092\u2096\u2104\u2104\u2109\u2109\u210c\u2115\u2117\u2117"+
		"\u211a\u211f\u2126\u2126\u2128\u2128\u212a\u212a\u212c\u2133\u2135\u213b"+
		"\u213e\u2141\u2147\u214b\u2162\u2185\u2c02\u2c30\u2c32\u2c60\u2c82\u2ce6"+
		"\u2d02\u2d27\u2d32\u2d67\u2d71\u2d71\u2d82\u2d98\u2da2\u2da8\u2daa\u2db0"+
		"\u2db2\u2db8\u2dba\u2dc0\u2dc2\u2dc8\u2dca\u2dd0\u2dd2\u2dd8\u2dda\u2de0"+
		"\u3007\u3009\u3023\u302b\u3033\u3037\u303a\u303e\u3043\u3098\u309d\u30a1"+
		"\u30a3\u30fc\u30fe\u3101\u3107\u312e\u3133\u3190\u31a2\u31b9\u31f2\u3201"+
		"\u3402\u4db7\u4e02\u9fbd\ua002\ua48e\ua802\ua803\ua805\ua807\ua809\ua80c"+
		"\ua80e\ua824\uac02\ud7a5\uf902\ufa2f\ufa32\ufa6c\ufa72\ufadb\ufb02\ufb08"+
		"\ufb15\ufb19\ufb1f\ufb1f\ufb21\ufb2a\ufb2c\ufb38\ufb3a\ufb3e\ufb40\ufb40"+
		"\ufb42\ufb43\ufb45\ufb46\ufb48\ufbb3\ufbd5\ufd3f\ufd52\ufd91\ufd94\ufdc9"+
		"\ufdf2\ufdfd\ufe72\ufe76\ufe78\ufefe\uff23\uff3c\uff43\uff5c\uff68\uffc0"+
		"\uffc4\uffc9\uffcc\uffd1\uffd4\uffd9\uffdc\uffde\2\u0398\2\3\3\2\2\2\2"+
		"\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2"+
		"\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2"+
		"\33\3\2\2\2\2\35\3\2\2\2\2\37\3\2\2\2\2!\3\2\2\2\2#\3\2\2\2\2%\3\2\2\2"+
		"\2\'\3\2\2\2\2)\3\2\2\2\2+\3\2\2\2\2-\3\2\2\2\2/\3\2\2\2\2\61\3\2\2\2"+
		"\2\63\3\2\2\2\2\65\3\2\2\2\2\67\3\2\2\2\29\3\2\2\2\2;\3\2\2\2\2=\3\2\2"+
		"\2\2?\3\2\2\2\2A\3\2\2\2\2C\3\2\2\2\2E\3\2\2\2\2G\3\2\2\2\2I\3\2\2\2\2"+
		"K\3\2\2\2\2M\3\2\2\2\2O\3\2\2\2\2Q\3\2\2\2\2S\3\2\2\2\2U\3\2\2\2\2W\3"+
		"\2\2\2\2Y\3\2\2\2\2[\3\2\2\2\2]\3\2\2\2\2_\3\2\2\2\2a\3\2\2\2\2c\3\2\2"+
		"\2\2e\3\2\2\2\2g\3\2\2\2\2i\3\2\2\2\2k\3\2\2\2\2m\3\2\2\2\2o\3\2\2\2\2"+
		"q\3\2\2\2\2s\3\2\2\2\2u\3\2\2\2\2w\3\2\2\2\2y\3\2\2\2\2{\3\2\2\2\2}\3"+
		"\2\2\2\2\177\3\2\2\2\2\u0081\3\2\2\2\2\u0083\3\2\2\2\2\u0085\3\2\2\2\2"+
		"\u0087\3\2\2\2\2\u0089\3\2\2\2\2\u008b\3\2\2\2\2\u008d\3\2\2\2\2\u008f"+
		"\3\2\2\2\2\u0091\3\2\2\2\2\u0093\3\2\2\2\2\u0095\3\2\2\2\2\u0097\3\2\2"+
		"\2\2\u0099\3\2\2\2\2\u009b\3\2\2\2\2\u009d\3\2\2\2\2\u009f\3\2\2\2\2\u00a1"+
		"\3\2\2\2\2\u00a3\3\2\2\2\2\u00a5\3\2\2\2\2\u00a7\3\2\2\2\2\u00a9\3\2\2"+
		"\2\2\u00ab\3\2\2\2\2\u00ad\3\2\2\2\2\u00af\3\2\2\2\2\u00b1\3\2\2\2\2\u00b3"+
		"\3\2\2\2\2\u00b5\3\2\2\2\2\u00b7\3\2\2\2\2\u00b9\3\2\2\2\2\u00bb\3\2\2"+
		"\2\2\u00bd\3\2\2\2\2\u00bf\3\2\2\2\2\u00c1\3\2\2\2\2\u00c3\3\2\2\2\2\u00c5"+
		"\3\2\2\2\2\u00c7\3\2\2\2\2\u00c9\3\2\2\2\3\u00e9\3\2\2\2\5\u00ed\3\2\2"+
		"\2\7\u00f4\3\2\2\2\t\u00fa\3\2\2\2\13\u00ff\3\2\2\2\r\u0106\3\2\2\2\17"+
		"\u010f\3\2\2\2\21\u0112\3\2\2\2\23\u0119\3\2\2\2\25\u0120\3\2\2\2\27\u0123"+
		"\3\2\2\2\31\u0128\3\2\2\2\33\u012d\3\2\2\2\35\u0133\3\2\2\2\37\u0137\3"+
		"\2\2\2!\u013a\3\2\2\2#\u013e\3\2\2\2%\u0143\3\2\2\2\'\u014b\3\2\2\2)\u0150"+
		"\3\2\2\2+\u0157\3\2\2\2-\u015e\3\2\2\2/\u0161\3\2\2\2\61\u0165\3\2\2\2"+
		"\63\u0169\3\2\2\2\65\u016c\3\2\2\2\67\u0172\3\2\2\29\u0178\3\2\2\2;\u017c"+
		"\3\2\2\2=\u0181\3\2\2\2?\u018a\3\2\2\2A\u0190\3\2\2\2C\u0196\3\2\2\2E"+
		"\u019c\3\2\2\2G\u01a2\3\2\2\2I\u01a7\3\2\2\2K\u01ac\3\2\2\2M\u01b2\3\2"+
		"\2\2O\u01b9\3\2\2\2Q\u01be\3\2\2\2S\u01c6\3\2\2\2U\u01c8\3\2\2\2W\u01cc"+
		"\3\2\2\2Y\u01ce\3\2\2\2[\u01d0\3\2\2\2]\u01d2\3\2\2\2_\u01d4\3\2\2\2a"+
		"\u01d6\3\2\2\2c\u01d9\3\2\2\2e\u01db\3\2\2\2g\u01dd\3\2\2\2i\u01df\3\2"+
		"\2\2k\u01e1\3\2\2\2m\u01e4\3\2\2\2o\u01e7\3\2\2\2q\u01e9\3\2\2\2s\u01eb"+
		"\3\2\2\2u\u01ed\3\2\2\2w\u01ef\3\2\2\2y\u01f2\3\2\2\2{\u01f4\3\2\2\2}"+
		"\u01f6\3\2\2\2\177\u01f8\3\2\2\2\u0081\u01fb\3\2\2\2\u0083\u01fe\3\2\2"+
		"\2\u0085\u0201\3\2\2\2\u0087\u0204\3\2\2\2\u0089\u0207\3\2\2\2\u008b\u0209"+
		"\3\2\2\2\u008d\u020c\3\2\2\2\u008f\u020f\3\2\2\2\u0091\u0212\3\2\2\2\u0093"+
		"\u0215\3\2\2\2\u0095\u0218\3\2\2\2\u0097\u021b\3\2\2\2\u0099\u021e\3\2"+
		"\2\2\u009b\u0221\3\2\2\2\u009d\u0224\3\2\2\2\u009f\u0227\3\2\2\2\u00a1"+
		"\u022b\3\2\2\2\u00a3\u022f\3\2\2\2\u00a5\u0233\3\2\2\2\u00a7\u0252\3\2"+
		"\2\2\u00a9\u0260\3\2\2\2\u00ab\u0262\3\2\2\2\u00ad\u0269\3\2\2\2\u00af"+
		"\u0270\3\2\2\2\u00b1\u027d\3\2\2\2\u00b3\u0281\3\2\2\2\u00b5\u0283\3\2"+
		"\2\2\u00b7\u0286\3\2\2\2\u00b9\u0289\3\2\2\2\u00bb\u028c\3\2\2\2\u00bd"+
		"\u028f\3\2\2\2\u00bf\u0292\3\2\2\2\u00c1\u0295\3\2\2\2\u00c3\u029c\3\2"+
		"\2\2\u00c5\u02a7\3\2\2\2\u00c7\u02ad\3\2\2\2\u00c9\u02b5\3\2\2\2\u00cb"+
		"\u02d8\3\2\2\2\u00cd\u02f4\3\2\2\2\u00cf\u02fc\3\2\2\2\u00d1\u02ff\3\2"+
		"\2\2\u00d3\u0315\3\2\2\2\u00d5\u0329\3\2\2\2\u00d7\u033d\3\2\2\2\u00d9"+
		"\u0359\3\2\2\2\u00db\u035d\3\2\2\2\u00dd\u0360\3\2\2\2\u00df\u0363\3\2"+
		"\2\2\u00e1\u0366\3\2\2\2\u00e3\u0368\3\2\2\2\u00e5\u036d\3\2\2\2\u00e7"+
		"\u0370\3\2\2\2\u00e9\u00ea\7f\2\2\u00ea\u00eb\7g\2\2\u00eb\u00ec\7h\2"+
		"\2\u00ec\4\3\2\2\2\u00ed\u00ee\7t\2\2\u00ee\u00ef\7g\2\2\u00ef\u00f0\7"+
		"v\2\2\u00f0\u00f1\7w\2\2\u00f1\u00f2\7t\2\2\u00f2\u00f3\7p\2\2\u00f3\6"+
		"\3\2\2\2\u00f4\u00f5\7t\2\2\u00f5\u00f6\7c\2\2\u00f6\u00f7\7k\2\2\u00f7"+
		"\u00f8\7u\2\2\u00f8\u00f9\7g\2\2\u00f9\b\3\2\2\2\u00fa\u00fb\7h\2\2\u00fb"+
		"\u00fc\7t\2\2\u00fc\u00fd\7q\2\2\u00fd\u00fe\7o\2\2\u00fe\n\3\2\2\2\u00ff"+
		"\u0100\7k\2\2\u0100\u0101\7o\2\2\u0101\u0102\7r\2\2\u0102\u0103\7q\2\2"+
		"\u0103\u0104\7t\2\2\u0104\u0105\7v\2\2\u0105\f\3\2\2\2\u0106\u0107\7p"+
		"\2\2\u0107\u0108\7q\2\2\u0108\u0109\7p\2\2\u0109\u010a\7n\2\2\u010a\u010b"+
		"\7q\2\2\u010b\u010c\7e\2\2\u010c\u010d\7c\2\2\u010d\u010e\7n\2\2\u010e"+
		"\16\3\2\2\2\u010f\u0110\7c\2\2\u0110\u0111\7u\2\2\u0111\20\3\2\2\2\u0112"+
		"\u0113\7i\2\2\u0113\u0114\7n\2\2\u0114\u0115\7q\2\2\u0115\u0116\7d\2\2"+
		"\u0116\u0117\7c\2\2\u0117\u0118\7n\2\2\u0118\22\3\2\2\2\u0119\u011a\7"+
		"c\2\2\u011a\u011b\7u\2\2\u011b\u011c\7u\2\2\u011c\u011d\7g\2\2\u011d\u011e"+
		"\7t\2\2\u011e\u011f\7v\2\2\u011f\24\3\2\2\2\u0120\u0121\7k\2\2\u0121\u0122"+
		"\7h\2\2\u0122\26\3\2\2\2\u0123\u0124\7g\2\2\u0124\u0125\7n\2\2\u0125\u0126"+
		"\7k\2\2\u0126\u0127\7h\2\2\u0127\30\3\2\2\2\u0128\u0129\7g\2\2\u0129\u012a"+
		"\7n\2\2\u012a\u012b\7u\2\2\u012b\u012c\7g\2\2\u012c\32\3\2\2\2\u012d\u012e"+
		"\7y\2\2\u012e\u012f\7j\2\2\u012f\u0130\7k\2\2\u0130\u0131\7n\2\2\u0131"+
		"\u0132\7g\2\2\u0132\34\3\2\2\2\u0133\u0134\7h\2\2\u0134\u0135\7q\2\2\u0135"+
		"\u0136\7t\2\2\u0136\36\3\2\2\2\u0137\u0138\7k\2\2\u0138\u0139\7p\2\2\u0139"+
		" \3\2\2\2\u013a\u013b\7v\2\2\u013b\u013c\7t\2\2\u013c\u013d\7{\2\2\u013d"+
		"\"\3\2\2\2\u013e\u013f\7P\2\2\u013f\u0140\7q\2\2\u0140\u0141\7p\2\2\u0141"+
		"\u0142\7g\2\2\u0142$\3\2\2\2\u0143\u0144\7h\2\2\u0144\u0145\7k\2\2\u0145"+
		"\u0146\7p\2\2\u0146\u0147\7c\2\2\u0147\u0148\7n\2\2\u0148\u0149\7n\2\2"+
		"\u0149\u014a\7{\2\2\u014a&\3\2\2\2\u014b\u014c\7y\2\2\u014c\u014d\7k\2"+
		"\2\u014d\u014e\7v\2\2\u014e\u014f\7j\2\2\u014f(\3\2\2\2\u0150\u0151\7"+
		"g\2\2\u0151\u0152\7z\2\2\u0152\u0153\7e\2\2\u0153\u0154\7g\2\2\u0154\u0155"+
		"\7r\2\2\u0155\u0156\7v\2\2\u0156*\3\2\2\2\u0157\u0158\7n\2\2\u0158\u0159"+
		"\7c\2\2\u0159\u015a\7o\2\2\u015a\u015b\7d\2\2\u015b\u015c\7f\2\2\u015c"+
		"\u015d\7c\2\2\u015d,\3\2\2\2\u015e\u015f\7q\2\2\u015f\u0160\7t\2\2\u0160"+
		".\3\2\2\2\u0161\u0162\7c\2\2\u0162\u0163\7p\2\2\u0163\u0164\7f\2\2\u0164"+
		"\60\3\2\2\2\u0165\u0166\7p\2\2\u0166\u0167\7q\2\2\u0167\u0168\7v\2\2\u0168"+
		"\62\3\2\2\2\u0169\u016a\7k\2\2\u016a\u016b\7u\2\2\u016b\64\3\2\2\2\u016c"+
		"\u016d\7e\2\2\u016d\u016e\7n\2\2\u016e\u016f\7c\2\2\u016f\u0170\7u\2\2"+
		"\u0170\u0171\7u\2\2\u0171\66\3\2\2\2\u0172\u0173\7{\2\2\u0173\u0174\7"+
		"k\2\2\u0174\u0175\7g\2\2\u0175\u0176\7n\2\2\u0176\u0177\7f\2\2\u01778"+
		"\3\2\2\2\u0178\u0179\7f\2\2\u0179\u017a\7g\2\2\u017a\u017b\7n\2\2\u017b"+
		":\3\2\2\2\u017c\u017d\7r\2\2\u017d\u017e\7c\2\2\u017e\u017f\7u\2\2\u017f"+
		"\u0180\7u\2\2\u0180<\3\2\2\2\u0181\u0182\7e\2\2\u0182\u0183\7q\2\2\u0183"+
		"\u0184\7p\2\2\u0184\u0185\7v\2\2\u0185\u0186\7k\2\2\u0186\u0187\7p\2\2"+
		"\u0187\u0188\7w\2\2\u0188\u0189\7g\2\2\u0189>\3\2\2\2\u018a\u018b\7d\2"+
		"\2\u018b\u018c\7t\2\2\u018c\u018d\7g\2\2\u018d\u018e\7c\2\2\u018e\u018f"+
		"\7m\2\2\u018f@\3\2\2\2\u0190\u0191\7c\2\2\u0191\u0192\7u\2\2\u0192\u0193"+
		"\7{\2\2\u0193\u0194\7p\2\2\u0194\u0195\7e\2\2\u0195B\3\2\2\2\u0196\u0197"+
		"\7c\2\2\u0197\u0198\7y\2\2\u0198\u0199\7c\2\2\u0199\u019a\7k\2\2\u019a"+
		"\u019b\7v\2\2\u019bD\3\2\2\2\u019c\u019d\7r\2\2\u019d\u019e\7t\2\2\u019e"+
		"\u019f\7k\2\2\u019f\u01a0\7p\2\2\u01a0\u01a1\7v\2\2\u01a1F\3\2\2\2\u01a2"+
		"\u01a3\7g\2\2\u01a3\u01a4\7z\2\2\u01a4\u01a5\7g\2\2\u01a5\u01a6\7e\2\2"+
		"\u01a6H\3\2\2\2\u01a7\u01a8\7V\2\2\u01a8\u01a9\7t\2\2\u01a9\u01aa\7w\2"+
		"\2\u01aa\u01ab\7g\2\2\u01abJ\3\2\2\2\u01ac\u01ad\7H\2\2\u01ad\u01ae\7"+
		"c\2\2\u01ae\u01af\7n\2\2\u01af\u01b0\7u\2\2\u01b0\u01b1\7g\2\2\u01b1L"+
		"\3\2\2\2\u01b2\u01b3\7u\2\2\u01b3\u01b4\7y\2\2\u01b4\u01b5\7k\2\2\u01b5"+
		"\u01b6\7v\2\2\u01b6\u01b7\7e\2\2\u01b7\u01b8\7j\2\2\u01b8N\3\2\2\2\u01b9"+
		"\u01ba\7e\2\2\u01ba\u01bb\7c\2\2\u01bb\u01bc\7u\2\2\u01bc\u01bd\7g\2\2"+
		"\u01bdP\3\2\2\2\u01be\u01bf\7f\2\2\u01bf\u01c0\7g\2\2\u01c0\u01c1\7h\2"+
		"\2\u01c1\u01c2\7c\2\2\u01c2\u01c3\7w\2\2\u01c3\u01c4\7n\2\2\u01c4\u01c5"+
		"\7v\2\2\u01c5R\3\2\2\2\u01c6\u01c7\7\60\2\2\u01c7T\3\2\2\2\u01c8\u01c9"+
		"\7\60\2\2\u01c9\u01ca\7\60\2\2\u01ca\u01cb\7\60\2\2\u01cbV\3\2\2\2\u01cc"+
		"\u01cd\7b\2\2\u01cdX\3\2\2\2\u01ce\u01cf\7,\2\2\u01cfZ\3\2\2\2\u01d0\u01d1"+
		"\7.\2\2\u01d1\\\3\2\2\2\u01d2\u01d3\7<\2\2\u01d3^\3\2\2\2\u01d4\u01d5"+
		"\7=\2\2\u01d5`\3\2\2\2\u01d6\u01d7\7,\2\2\u01d7\u01d8\7,\2\2\u01d8b\3"+
		"\2\2\2\u01d9\u01da\7?\2\2\u01dad\3\2\2\2\u01db\u01dc\7~\2\2\u01dcf\3\2"+
		"\2\2\u01dd\u01de\7`\2\2\u01deh\3\2\2\2\u01df\u01e0\7(\2\2\u01e0j\3\2\2"+
		"\2\u01e1\u01e2\7>\2\2\u01e2\u01e3\7>\2\2\u01e3l\3\2\2\2\u01e4\u01e5\7"+
		"@\2\2\u01e5\u01e6\7@\2\2\u01e6n\3\2\2\2\u01e7\u01e8\7-\2\2\u01e8p\3\2"+
		"\2\2\u01e9\u01ea\7/\2\2\u01ear\3\2\2\2\u01eb\u01ec\7\61\2\2\u01ect\3\2"+
		"\2\2\u01ed\u01ee\7\'\2\2\u01eev\3\2\2\2\u01ef\u01f0\7\61\2\2\u01f0\u01f1"+
		"\7\61\2\2\u01f1x\3\2\2\2\u01f2\u01f3\7\u0080\2\2\u01f3z\3\2\2\2\u01f4"+
		"\u01f5\7>\2\2\u01f5|\3\2\2\2\u01f6\u01f7\7@\2\2\u01f7~\3\2\2\2\u01f8\u01f9"+
		"\7?\2\2\u01f9\u01fa\7?\2\2\u01fa\u0080\3\2\2\2\u01fb\u01fc\7@\2\2\u01fc"+
		"\u01fd\7?\2\2\u01fd\u0082\3\2\2\2\u01fe\u01ff\7>\2\2\u01ff\u0200\7?\2"+
		"\2\u0200\u0084\3\2\2\2\u0201\u0202\7>\2\2\u0202\u0203\7@\2\2\u0203\u0086"+
		"\3\2\2\2\u0204\u0205\7#\2\2\u0205\u0206\7?\2\2\u0206\u0088\3\2\2\2\u0207"+
		"\u0208\7B\2\2\u0208\u008a\3\2\2\2\u0209\u020a\7/\2\2\u020a\u020b\7@\2"+
		"\2\u020b\u008c\3\2\2\2\u020c\u020d\7-\2\2\u020d\u020e\7?\2\2\u020e\u008e"+
		"\3\2\2\2\u020f\u0210\7/\2\2\u0210\u0211\7?\2\2\u0211\u0090\3\2\2\2\u0212"+
		"\u0213\7,\2\2\u0213\u0214\7?\2\2\u0214\u0092\3\2\2\2\u0215\u0216\7B\2"+
		"\2\u0216\u0217\7?\2\2\u0217\u0094\3\2\2\2\u0218\u0219\7\61\2\2\u0219\u021a"+
		"\7?\2\2\u021a\u0096\3\2\2\2\u021b\u021c\7\'\2\2\u021c\u021d\7?\2\2\u021d"+
		"\u0098\3\2\2\2\u021e\u021f\7(\2\2\u021f\u0220\7?\2\2\u0220\u009a\3\2\2"+
		"\2\u0221\u0222\7~\2\2\u0222\u0223\7?\2\2\u0223\u009c\3\2\2\2\u0224\u0225"+
		"\7`\2\2\u0225\u0226\7?\2\2\u0226\u009e\3\2\2\2\u0227\u0228\7>\2\2\u0228"+
		"\u0229\7>\2\2\u0229\u022a\7?\2\2\u022a\u00a0\3\2\2\2\u022b\u022c\7@\2"+
		"\2\u022c\u022d\7@\2\2\u022d\u022e\7?\2\2\u022e\u00a2\3\2\2\2\u022f\u0230"+
		"\7,\2\2\u0230\u0231\7,\2\2\u0231\u0232\7?\2\2\u0232\u00a4\3\2\2\2\u0233"+
		"\u0234\7\61\2\2\u0234\u0235\7\61\2\2\u0235\u0236\7?\2\2\u0236\u00a6\3"+
		"\2\2\2\u0237\u0241\t\2\2\2\u0238\u023a\t\3\2\2\u0239\u023b\t\4\2\2\u023a"+
		"\u0239\3\2\2\2\u023a\u023b\3\2\2\2\u023b\u0241\3\2\2\2\u023c\u023e\t\4"+
		"\2\2\u023d\u023f\t\3\2\2\u023e\u023d\3\2\2\2\u023e\u023f\3\2\2\2\u023f"+
		"\u0241\3\2\2\2\u0240\u0237\3\2\2\2\u0240\u0238\3\2\2\2\u0240\u023c\3\2"+
		"\2\2\u0240\u0241\3\2\2\2\u0241\u0244\3\2\2\2\u0242\u0245\5\u00cbf\2\u0243"+
		"\u0245\5\u00cdg\2\u0244\u0242\3\2\2\2\u0244\u0243\3\2\2\2\u0245\u0253"+
		"\3\2\2\2\u0246\u0248\t\5\2\2\u0247\u0249\t\4\2\2\u0248\u0247\3\2\2\2\u0248"+
		"\u0249\3\2\2\2\u0249\u024d\3\2\2\2\u024a\u024b\t\4\2\2\u024b\u024d\t\5"+
		"\2\2\u024c\u0246\3\2\2\2\u024c\u024a\3\2\2\2\u024d\u0250\3\2\2\2\u024e"+
		"\u0251\5\u00d7l\2\u024f\u0251\5\u00d9m\2\u0250\u024e\3\2\2\2\u0250\u024f"+
		"\3\2\2\2\u0251\u0253\3\2\2\2\u0252\u0240\3\2\2\2\u0252\u024c\3\2\2\2\u0253"+
		"\u00a8\3\2\2\2\u0254\u0258\t\6\2\2\u0255\u0257\t\7\2\2\u0256\u0255\3\2"+
		"\2\2\u0257\u025a\3\2\2\2\u0258\u0256\3\2\2\2\u0258\u0259\3\2\2\2\u0259"+
		"\u0261\3\2\2\2\u025a\u0258\3\2\2\2\u025b\u025d\7\62\2\2\u025c\u025b\3"+
		"\2\2\2\u025d\u025e\3\2\2\2\u025e\u025c\3\2\2\2\u025e\u025f\3\2\2\2\u025f"+
		"\u0261\3\2\2\2\u0260\u0254\3\2\2\2\u0260\u025c\3\2\2\2\u0261\u00aa\3\2"+
		"\2\2\u0262\u0263\7\62\2\2\u0263\u0265\t\b\2\2\u0264\u0266\t\t\2\2\u0265"+
		"\u0264\3\2\2\2\u0266\u0267\3\2\2\2\u0267\u0265\3\2\2\2\u0267\u0268\3\2"+
		"\2\2\u0268\u00ac\3\2\2\2\u0269\u026a\7\62\2\2\u026a\u026c\t\n\2\2\u026b"+
		"\u026d\t\13\2\2\u026c\u026b\3\2\2\2\u026d\u026e\3\2\2\2\u026e\u026c\3"+
		"\2\2\2\u026e\u026f\3\2\2\2\u026f\u00ae\3\2\2\2\u0270\u0271\7\62\2\2\u0271"+
		"\u0273\t\5\2\2\u0272\u0274\t\f\2\2\u0273\u0272\3\2\2\2\u0274\u0275\3\2"+
		"\2\2\u0275\u0273\3\2\2\2\u0275\u0276\3\2\2\2\u0276\u00b0\3\2\2\2\u0277"+
		"\u027e\5\u00d3j\2\u0278\u027a\t\7\2\2\u0279\u0278\3\2\2\2\u027a\u027b"+
		"\3\2\2\2\u027b\u0279\3\2\2\2\u027b\u027c\3\2\2\2\u027c\u027e\3\2\2\2\u027d"+
		"\u0277\3\2\2\2\u027d\u0279\3\2\2\2\u027e\u027f\3\2\2\2\u027f\u0280\t\r"+
		"\2\2\u0280\u00b2\3\2\2\2\u0281\u0282\5\u00d3j\2\u0282\u00b4\3\2\2\2\u0283"+
		"\u0284\7*\2\2\u0284\u0285\b[\2\2\u0285\u00b6\3\2\2\2\u0286\u0287\7+\2"+
		"\2\u0287\u0288\b\\\3\2\u0288\u00b8\3\2\2\2\u0289\u028a\7}\2\2\u028a\u028b"+
		"\b]\4\2\u028b\u00ba\3\2\2\2\u028c\u028d\7\177\2\2\u028d\u028e\b^\5\2\u028e"+
		"\u00bc\3\2\2\2\u028f\u0290\7]\2\2\u0290\u0291\b_\6\2\u0291\u00be\3\2\2"+
		"\2\u0292\u0293\7_\2\2\u0293\u0294\b`\7\2\u0294\u00c0\3\2\2\2\u0295\u0299"+
		"\5\u00e7t\2\u0296\u0298\5\u00e5s\2\u0297\u0296\3\2\2\2\u0298\u029b\3\2"+
		"\2\2\u0299\u0297\3\2\2\2\u0299\u029a\3\2\2\2\u029a\u00c2\3\2\2\2\u029b"+
		"\u0299\3\2\2\2\u029c\u02a0\7^\2\2\u029d\u029f\t\16\2\2\u029e\u029d\3\2"+
		"\2\2\u029f\u02a2\3\2\2\2\u02a0\u029e\3\2\2\2\u02a0\u02a1\3\2\2\2\u02a1"+
		"\u02a3\3\2\2\2\u02a2\u02a0\3\2\2\2\u02a3\u02a4\5\u00d1i\2\u02a4\u02a5"+
		"\3\2\2\2\u02a5\u02a6\bb\b\2\u02a6\u00c4\3\2\2\2\u02a7\u02a8\5\u00d1i\2"+
		"\u02a8\u02a9\bc\t\2\u02a9\u02aa\3\2\2\2\u02aa\u02ab\bc\b\2\u02ab\u00c6"+
		"\3\2\2\2\u02ac\u02ae\t\16\2\2\u02ad\u02ac\3\2\2\2\u02ae\u02af\3\2\2\2"+
		"\u02af\u02ad\3\2\2\2\u02af\u02b0\3\2\2\2\u02b0\u02b1\3\2\2\2\u02b1\u02b2"+
		"\bd\n\2\u02b2\u02b3\3\2\2\2\u02b3\u02b4\bd\b\2\u02b4\u00c8\3\2\2\2\u02b5"+
		"\u02b9\7%\2\2\u02b6\u02b8\n\17\2\2\u02b7\u02b6\3\2\2\2\u02b8\u02bb\3\2"+
		"\2\2\u02b9\u02b7\3\2\2\2\u02b9\u02ba\3\2\2\2\u02ba\u02bc\3\2\2\2\u02bb"+
		"\u02b9\3\2\2\2\u02bc\u02bd\be\b\2\u02bd\u00ca\3\2\2\2\u02be\u02c7\7)\2"+
		"\2\u02bf\u02c2\7^\2\2\u02c0\u02c3\5\u00d1i\2\u02c1\u02c3\13\2\2\2\u02c2"+
		"\u02c0\3\2\2\2\u02c2\u02c1\3\2\2\2\u02c3\u02c6\3\2\2\2\u02c4\u02c6\n\20"+
		"\2\2\u02c5\u02bf\3\2\2\2\u02c5\u02c4\3\2\2\2\u02c6\u02c9\3\2\2\2\u02c7"+
		"\u02c5\3\2\2\2\u02c7\u02c8\3\2\2\2\u02c8\u02ca\3\2\2\2\u02c9\u02c7\3\2"+
		"\2\2\u02ca\u02d9\7)\2\2\u02cb\u02d4\7$\2\2\u02cc\u02cf\7^\2\2\u02cd\u02d0"+
		"\5\u00d1i\2\u02ce\u02d0\13\2\2\2\u02cf\u02cd\3\2\2\2\u02cf\u02ce\3\2\2"+
		"\2\u02d0\u02d3\3\2\2\2\u02d1\u02d3\n\21\2\2\u02d2\u02cc\3\2\2\2\u02d2"+
		"\u02d1\3\2\2\2\u02d3\u02d6\3\2\2\2\u02d4\u02d2\3\2\2\2\u02d4\u02d5\3\2"+
		"\2\2\u02d5\u02d7\3\2\2\2\u02d6\u02d4\3\2\2\2\u02d7\u02d9\7$\2\2\u02d8"+
		"\u02be\3\2\2\2\u02d8\u02cb\3\2\2\2\u02d9\u00cc\3\2\2\2\u02da\u02db\7)"+
		"\2\2\u02db\u02dc\7)\2\2\u02dc\u02dd\7)\2\2\u02dd\u02e1\3\2\2\2\u02de\u02e0"+
		"\5\u00cfh\2\u02df\u02de\3\2\2\2\u02e0\u02e3\3\2\2\2\u02e1\u02e2\3\2\2"+
		"\2\u02e1\u02df\3\2\2\2\u02e2\u02e4\3\2\2\2\u02e3\u02e1\3\2\2\2\u02e4\u02e5"+
		"\7)\2\2\u02e5\u02e6\7)\2\2\u02e6\u02f5\7)\2\2\u02e7\u02e8\7$\2\2\u02e8"+
		"\u02e9\7$\2\2\u02e9\u02ea\7$\2\2\u02ea\u02ee\3\2\2\2\u02eb\u02ed\5\u00cf"+
		"h\2\u02ec\u02eb\3\2\2\2\u02ed\u02f0\3\2\2\2\u02ee\u02ef\3\2\2\2\u02ee"+
		"\u02ec\3\2\2\2\u02ef\u02f1\3\2\2\2\u02f0\u02ee\3\2\2\2\u02f1\u02f2\7$"+
		"\2\2\u02f2\u02f3\7$\2\2\u02f3\u02f5\7$\2\2\u02f4\u02da\3\2\2\2\u02f4\u02e7"+
		"\3\2\2\2\u02f5\u00ce\3\2\2\2\u02f6\u02fd\n\22\2\2\u02f7\u02fa\7^\2\2\u02f8"+
		"\u02fb\5\u00d1i\2\u02f9\u02fb\13\2\2\2\u02fa\u02f8\3\2\2\2\u02fa\u02f9"+
		"\3\2\2\2\u02fb\u02fd\3\2\2\2\u02fc\u02f6\3\2\2\2\u02fc\u02f7\3\2\2\2\u02fd"+
		"\u00d0\3\2\2\2\u02fe\u0300\7\17\2\2\u02ff\u02fe\3\2\2\2\u02ff\u0300\3"+
		"\2\2\2\u0300\u0301\3\2\2\2\u0301\u0302\7\f\2\2\u0302\u00d2\3\2\2\2\u0303"+
		"\u0305\t\7\2\2\u0304\u0303\3\2\2\2\u0305\u0306\3\2\2\2\u0306\u0304\3\2"+
		"\2\2\u0306\u0307\3\2\2\2\u0307\u030a\3\2\2\2\u0308\u030a\5\u00d5k\2\u0309"+
		"\u0304\3\2\2\2\u0309\u0308\3\2\2\2\u030a\u030b\3\2\2\2\u030b\u030d\t\23"+
		"\2\2\u030c\u030e\t\24\2\2\u030d\u030c\3\2\2\2\u030d\u030e\3\2\2\2\u030e"+
		"\u0310\3\2\2\2\u030f\u0311\t\7\2\2\u0310\u030f\3\2\2\2\u0311\u0312\3\2"+
		"\2\2\u0312\u0310\3\2\2\2\u0312\u0313\3\2\2\2\u0313\u0316\3\2\2\2\u0314"+
		"\u0316\5\u00d5k\2\u0315\u0309\3\2\2\2\u0315\u0314\3\2\2\2\u0316\u00d4"+
		"\3\2\2\2\u0317\u0319\t\7\2\2\u0318\u0317\3\2\2\2\u0319\u031c\3\2\2\2\u031a"+
		"\u0318\3\2\2\2\u031a\u031b\3\2\2\2\u031b\u031d\3\2\2\2\u031c\u031a\3\2"+
		"\2\2\u031d\u031f\7\60\2\2\u031e\u0320\t\7\2\2\u031f\u031e\3\2\2\2\u0320"+
		"\u0321\3\2\2\2\u0321\u031f\3\2\2\2\u0321\u0322\3\2\2\2\u0322\u032a\3\2"+
		"\2\2\u0323\u0325\t\7\2\2\u0324\u0323\3\2\2\2\u0325\u0326\3\2\2\2\u0326"+
		"\u0324\3\2\2\2\u0326\u0327\3\2\2\2\u0327\u0328\3\2\2\2\u0328\u032a\7\60"+
		"\2\2\u0329\u031a\3\2\2\2\u0329\u0324\3\2\2\2\u032a\u00d6\3\2\2\2\u032b"+
		"\u0330\7)\2\2\u032c\u032f\5\u00ddo\2\u032d\u032f\5\u00e3r\2\u032e\u032c"+
		"\3\2\2\2\u032e\u032d\3\2\2\2\u032f\u0332\3\2\2\2\u0330\u032e\3\2\2\2\u0330"+
		"\u0331\3\2\2\2\u0331\u0333\3\2\2\2\u0332\u0330\3\2\2\2\u0333\u033e\7)"+
		"\2\2\u0334\u0339\7$\2\2\u0335\u0338\5\u00dfp\2\u0336\u0338\5\u00e3r\2"+
		"\u0337\u0335\3\2\2\2\u0337\u0336\3\2\2\2\u0338\u033b\3\2\2\2\u0339\u0337"+
		"\3\2\2\2\u0339\u033a\3\2\2\2\u033a\u033c\3\2\2\2\u033b\u0339\3\2\2\2\u033c"+
		"\u033e\7$\2\2\u033d\u032b\3\2\2\2\u033d\u0334\3\2\2\2\u033e\u00d8\3\2"+
		"\2\2\u033f\u0340\7)\2\2\u0340\u0341\7)\2\2\u0341\u0342\7)\2\2\u0342\u0346"+
		"\3\2\2\2\u0343\u0345\5\u00dbn\2\u0344\u0343\3\2\2\2\u0345\u0348\3\2\2"+
		"\2\u0346\u0347\3\2\2\2\u0346\u0344\3\2\2\2\u0347\u0349\3\2\2\2\u0348\u0346"+
		"\3\2\2\2\u0349\u034a\7)\2\2\u034a\u034b\7)\2\2\u034b\u035a\7)\2\2\u034c"+
		"\u034d\7$\2\2\u034d\u034e\7$\2\2\u034e\u034f\7$\2\2\u034f\u0353\3\2\2"+
		"\2\u0350\u0352\5\u00dbn\2\u0351\u0350\3\2\2\2\u0352\u0355\3\2\2\2\u0353"+
		"\u0354\3\2\2\2\u0353\u0351\3\2\2\2\u0354\u0356\3\2\2\2\u0355\u0353\3\2"+
		"\2\2\u0356\u0357\7$\2\2\u0357\u0358\7$\2\2\u0358\u035a\7$\2\2\u0359\u033f"+
		"\3\2\2\2\u0359\u034c\3\2\2\2\u035a\u00da\3\2\2\2\u035b\u035e\5\u00e1q"+
		"\2\u035c\u035e\5\u00e3r\2\u035d\u035b\3\2\2\2\u035d\u035c\3\2\2\2\u035e"+
		"\u00dc\3\2\2\2\u035f\u0361\t\25\2\2\u0360\u035f\3\2\2\2\u0361\u00de\3"+
		"\2\2\2\u0362\u0364\t\26\2\2\u0363\u0362\3\2\2\2\u0364\u00e0\3\2\2\2\u0365"+
		"\u0367\t\27\2\2\u0366\u0365\3\2\2\2\u0367\u00e2\3\2\2\2\u0368\u0369\7"+
		"^\2\2\u0369\u036a\t\30\2\2\u036a\u00e4\3\2\2\2\u036b\u036e\5\u00e7t\2"+
		"\u036c\u036e\t\31\2\2\u036d\u036b\3\2\2\2\u036d\u036c\3\2\2\2\u036e\u00e6"+
		"\3\2\2\2\u036f\u0371\t\32\2\2\u0370\u036f\3\2\2\2\u0371\u00e8\3\2\2\2"+
		";\2\u023a\u023e\u0240\u0244\u0248\u024c\u0250\u0252\u0258\u025e\u0260"+
		"\u0267\u026e\u0275\u027b\u027d\u0299\u02a0\u02af\u02b9\u02c2\u02c5\u02c7"+
		"\u02cf\u02d2\u02d4\u02d8\u02e1\u02ee\u02f4\u02fa\u02fc\u02ff\u0306\u0309"+
		"\u030d\u0312\u0315\u031a\u0321\u0326\u0329\u032e\u0330\u0337\u0339\u033d"+
		"\u0346\u0353\u0359\u035d\u0360\u0363\u0366\u036d\u0370\13\3[\2\3\\\3\3"+
		"]\4\3^\5\3_\6\3`\7\2\3\2\3c\b\3d\t";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}