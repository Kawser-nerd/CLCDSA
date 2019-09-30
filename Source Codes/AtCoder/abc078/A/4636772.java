class Main {
  public static void main(String[] args) {
    java.util.Scanner sc = new java.util.Scanner(System.in);
    String X = sc.next();
    String Y = sc.next();
    int x=0;
    int y=0;
    if(X.equals("A")) x=10;
    if(X.equals("B")) x=11;
    if(X.equals("C")) x=12;
    if(X.equals("D")) x=13;
    if(X.equals("E")) x=14;
    if(X.equals("F")) x=15;
    if(Y.equals("A")) y=10;
    if(Y.equals("B")) y=11;
    if(Y.equals("C")) y=12;
    if(Y.equals("D")) y=13;
    if(Y.equals("E")) y=14;
    if(Y.equals("F")) y=15;
    if(x==y){
      println("=");
    }else if(x>y){
      println(">");
    }else{
      println("<");
    }
  }
  
  /* ?????????? */
  static public void print(byte what) { System.out.print(what); System.out.flush(); }
  static public void print(boolean what) { System.out.print(what); System.out.flush(); }
  static public void print(char what) { System.out.print(what); System.out.flush(); }
  static public void print(int what) { System.out.print(what); System.out.flush(); }
  static public void print(long what) { System.out.print(what); System.out.flush(); }
  static public void print(float what) { System.out.print(what); System.out.flush(); }
  static public void print(double what) { System.out.print(what); System.out.flush(); }
  static public void print(String what) { System.out.print(what); System.out.flush(); }
  static public void print(Object... variables) { StringBuilder sb = new StringBuilder(); for (Object o : variables) { if (sb.length() != 0) { sb.append(" "); } if (o == null) { sb.append("null"); } else { sb.append(o.toString()); } } System.out.print(sb.toString()); }
  static public void println() { System.out.println(); }
  static public void println(byte what) { System.out.println(what); System.out.flush(); }
  static public void println(boolean what) { System.out.println(what); System.out.flush(); }
  static public void println(char what) { System.out.println(what); System.out.flush(); }
  static public void println(int what) { System.out.println(what); System.out.flush(); }
  static public void println(long what) { System.out.println(what); System.out.flush(); }
  static public void println(float what) { System.out.println(what); System.out.flush(); }
  static public void println(double what) { System.out.println(what); System.out.flush(); }
  static public void println(String what) { System.out.println(what); System.out.flush(); }
  static public void println(Object... variables) { print(variables); println(); }
  static public void println(Object what) { if (what == null) { System.out.println("null"); } else if (what.getClass().isArray()) { printArray(what); } else { System.out.println(what.toString()); System.out.flush(); } }
  static public void printArray(Object what) { if (what == null) { System.out.println("null"); } else { String name = what.getClass().getName(); if (name.charAt(0) == '[') { switch (name.charAt(1)) { case '[': System.out.println(what); break; case 'L': Object poo[] = (Object[]) what; for (int i = 0; i < poo.length; i++) { if (poo[i] instanceof String) { System.out.println("[" + i + "] \"" + poo[i] + "\""); } else { System.out.println("[" + i + "] " + poo[i]); } } break; case 'Z': boolean zz[] = (boolean[]) what; for (int i = 0; i < zz.length; i++) { System.out.println("[" + i + "] " + zz[i]); } break; case 'B': byte bb[] = (byte[]) what; for (int i = 0; i < bb.length; i++) { System.out.println("[" + i + "] " + bb[i]); } break; case 'C': char cc[] = (char[]) what; for (int i = 0; i < cc.length; i++) { System.out.println("[" + i + "] '" + cc[i] + "'"); } break; case 'I': int ii[] = (int[]) what; for (int i = 0; i < ii.length; i++) { System.out.println("[" + i + "] " + ii[i]); } break; case 'J': long jj[] = (long[]) what; for (int i = 0; i < jj.length; i++) { System.out.println("[" + i + "] " + jj[i]); } break; case 'F': float ff[] = (float[]) what; for (int i = 0; i < ff.length; i++) { System.out.println("[" + i + "] " + ff[i]); } break; case 'D': double dd[] = (double[]) what; for (int i = 0; i < dd.length; i++) { System.out.println("[" + i + "] " + dd[i]); } break; default: System.out.println(what); } } else { System.out.println(what); } } System.out.flush(); }}