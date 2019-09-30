public class Main {
    public static void main(String[] args) {
        java.util.Scanner c=new java.util.Scanner(System.in);
        String s=c.next(),t=c.next();
        java.util.regex.Matcher matcher=java.util.regex.Pattern.compile("(.*)"+t.replaceAll(".","[$0?]")+"(.*?)").matcher(s);
        System.out.println(matcher.matches()?matcher.replaceFirst("$1"+t+"$2").replace('?','a'):"UNRESTORABLE");
    }
}