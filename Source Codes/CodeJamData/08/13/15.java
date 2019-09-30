import java.math.BigInteger;

class CS {
    public static void main (String[] args) {
	BigInteger base = new BigInteger("523606797749978969640917366873127623544061835961152572427089724541052092563780489941441440837878227496950817615077378350425326772444707386358636012153345270886677817319187916581127664532263985658053576135041");
	BigInteger acc = new BigInteger("1");

	System.out.println("case 2 : printf(\"027\\n\"); break;");
	for (int i=1;i<=30;i++) {
	    acc = acc.multiply(base);
	    String accS = acc.toString();
	    //System.out.println(accS);
	    if (i>2) System.out.println("case " + i + " : printf(\"" + accS.substring(accS.length()-206*i-3,accS.length()-206*i) + "\\n\"); break;");
	}
    }
}
