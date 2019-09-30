import java.util.Scanner;


public class Bot {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int nbCase = s.nextInt();
        int nbButtons;
        int color;
        int button;
        int[] pos = new int[2];
        int[] time = new int[2];
        for (int numTest = 1 ; numTest <= nbCase ; numTest++) {
            s.nextLine();
            System.out.print("Case #");
            System.out.print(numTest);
            System.out.print(": ");
            pos[0] = 1;
            pos[1] = 1;
            time[0] = 0;
            time[1] = 0;
            nbButtons = s.nextInt();
            for (int numButton = 0 ; numButton < nbButtons ; numButton++) {
                color = (s.next().charAt(0) == 'B') ? 0 : 1;
                button = s.nextInt();
                time[color] += Math.abs(pos[color] - button);
                time[color] = Math.max(time[0], time[1]) + 1;
                pos[color] = button;
            }
            System.out.println(Math.max(time[0], time[1]));
        }
    }
}
