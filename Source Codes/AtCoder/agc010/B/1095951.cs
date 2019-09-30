using System;
public class Box {
    public static void Main() {
        long N = long.Parse(Console.ReadLine());
        string[] read = new string[N];
        read = Console.ReadLine().Split(' ');
        int[] A = new int[N];
        long sum = 0;
        long sumlo = 0;
        for (int i = 0; i < N; i++) {
            sumlo += i + 1;
        }
        for (int i = 0; i < N; i++) {
            A[i] = int.Parse(read[i]);
            sum += A[i];
        }
        if (sum % sumlo != 0) {
            Console.WriteLine("NO");
        } else {
            long loop = sum / sumlo;
            bool NO = false;
            long check = 0;
            for (int i = 0; i < N; i++) {
                if (i == N - 1) {
                    check = A[0] - A[N - 1];
                } else {
                    check = A[i + 1] - A[i];
                }
                NO = true;
                if ((check - loop) % N == 0) {
                    if (check - loop <= 0) {
                        if ((check - loop) / N >= -1 * loop) {
                            NO = false;
                        }
                    }
                }



                /*for (int j = 0; j <= loop; j++) {
                    NO = true;
                    if (i == N - 1) {
                        if (A[0] - A[N-1] == loop - j * N) {
                            NO = false;
                            break;
                        }
                    } else {
                        if (A[i + 1] - A[i] == loop - j * N) {
                            NO = false;
                            break;
                        }
                    }
                }*/

                if (NO) {
                    break;
                }
            }
            if (NO) {
                Console.WriteLine("NO");
            } else {
                Console.WriteLine("YES");
            }
        }


    }
}