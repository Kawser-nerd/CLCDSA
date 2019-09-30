import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        int n  = Integer.parseInt(input.readLine());
        int [] positions = new int[n + 1];
        int currentIndex = 1;
        for (int i = 1; i <= n; i++) {
            positions[i] = Integer.parseInt(input.readLine());
        }
        int count = 0;
        while (currentIndex != 2 && positions[currentIndex] > 0){
            int copyCurrentIndex = currentIndex;
            currentIndex = positions[currentIndex];
            positions[copyCurrentIndex] = -1;
            count++;
        }
        System.out.println(currentIndex == 2 ? count: -1);
    }

}