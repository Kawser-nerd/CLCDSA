using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AGC021C {
    class Program {
        static void Main(string[] args) {
            int[] input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int N = input[0];
            int M = input[1];
            int A = input[2];
            int B = input[3];
            bool ok = false;
            bool except = false;
            int Ndiv = N % 2;
            int Mdiv = M % 2;
            int Nnum = N / 2;
            int Mnum = M / 2;
            int Ad = A - Ndiv * Mnum >= 0 ? A - Ndiv * Mnum : 0;
            int Bd = B - Mdiv * Nnum >= 0 ? B - Mdiv * Nnum : 0;
            int AdBlock = (Ad + 1) / 2;
            int BdBlock = (Bd + 1) / 2;
            if (AdBlock + BdBlock <= Nnum * Mnum) {
                ok = true;
            }
            if (Ndiv == 1 && Mdiv == 1 && Ad % 2 == 1 && Bd % 2 == 1 && AdBlock + BdBlock == Nnum * Mnum + 1) {
                ok = true;
                except = true;
            }
            if (ok) {
                Console.WriteLine("YES");
                string[,] str = new string[N, M];
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < M; j++) {
                        str[i, j] = ".";
                    }
                }
                for (int i = 0; i < Ndiv * Mnum; i++) {
                    if (i < A) {
                        str[N - 1, i * 2] = "<";
                        str[N - 1, i * 2 + 1] = ">";
                    }
                }
                for (int i = 0; i < Mdiv * Nnum; i++) {
                    if (i < B) {
                        str[i * 2, M - 1] = "^";
                        str[i * 2 + 1, M - 1] = "v";
                    }
                }
                for (int i = 0; i < Ad / 2; i++) {
                    int x = (i / Mnum) * 2;
                    int y = (i % Mnum) * 2;
                    str[x, y] = "<";
                    str[x, y + 1] = ">";
                    str[x + 1, y] = "<";
                    str[x + 1, y + 1] = ">";
                }
                for (int i = 0; i < Bd / 2; i++) {
                    int x = ((i + Ad / 2) / Mnum) * 2;
                    int y = ((i + Ad / 2) % Mnum) * 2;
                    str[x, y] = "^";
                    str[x + 1, y] = "v";
                    str[x, y + 1] = "^";
                    str[x + 1, y + 1] = "v";
                }
                if (!except) {
                    int num = Ad / 2 + Bd / 2;
                    if (Ad % 2 == 1) {
                        int x = (num / Mnum) * 2;
                        int y = (num % Mnum) * 2;
                        str[x, y] = "<";
                        str[x, y + 1] = ">";
                        num++;
                    }
                    if (Bd % 2 == 1) {
                        int x = (num / Mnum) * 2;
                        int y = (num % Mnum) * 2;
                        str[x, y] = "^";
                        str[x + 1, y] = "v";
                        num++;
                    }
                } else {
                    str[N - 3, M - 3] = "<";
                    str[N - 3, M - 2] = ">";
                    str[N - 2, M - 3] = "^";
                    str[N - 1, M - 3] = "v";
                    str[N - 1, M - 2] = "<";
                    str[N - 1, M - 1] = ">";
                }
                for (int i = 0; i < N; i++) {
                    string ans = "";
                    for (int j = 0; j < M; j++) {
                        ans += str[i, j];
                    }
                    Console.WriteLine(ans);
                }
            } else {
                Console.WriteLine("NO");
            }
        }
    }
}