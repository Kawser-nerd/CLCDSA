package codejam2013;

import java.io.IOException;

abstract public class CodeJam2013 {

    abstract public void solveCases(String inputSize) throws IOException;

    public static void main(String[] args) {
        String inputSize = "s1";
        Round1AC.main(inputSize);
    }
}
