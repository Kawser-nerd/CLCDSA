using System;
using System.Collections.Generic;
using System.Text;

class Program {

    static void Main() {
        //M1();
        //M2();
        M3();
        //M4();
    }

    static void M1() {

        string sLines = Console.ReadLine();
        bool bManual = sLines.StartsWith("m");
        if (bManual) sLines = sLines.Substring(1);
        int iCases = int.Parse(sLines);

        for (int iCase = 1; iCase <= iCases; iCase++) {

            BigPockets o = new BigPockets();

            string s = Console.ReadLine();
            int N = int.Parse(s);
            List<string> dirs = new List<string>();
            List<int> reps = new List<int>();
            while (dirs.Count < N) {
                string[] s2 = Console.ReadLine().Split(' ');
                for (int i = 0; i < s2.Length; i+=2) {
                    dirs.Add(s2[i]);
                    reps.Add(int.Parse(s2[i + 1]));
                }
            }

            string sOut = o.Process(dirs.ToArray(), reps.ToArray());
            Console.WriteLine("Case #{0}: {1}", iCase, sOut);


            //string[] sOut = o.ProcessMulti(roads,city);
            //Console.WriteLine("Case #{0}:", iCase);
            //for (int j = 0; j < sOut.Length; j++) {
            //    Console.WriteLine(sOut[j]);
            //}
        }

        if (bManual) Console.ReadKey();
    }

    static void M2() {

        string sLines = Console.ReadLine();
        bool bManual = sLines.StartsWith("m");
        if (bManual) sLines = sLines.Substring(1);
        int iCases = int.Parse(sLines);

        for (int iCase = 1; iCase <= iCases; iCase++) {

            Portal o = new Portal();

            string s = Console.ReadLine();
            int R = int.Parse( s.Split(' ')[0]);
            int C = int.Parse(s.Split(' ')[1]);
            string[] map = new string[R];
            for (int i = 0; i < R; i++) {
                map[i]=Console.ReadLine();
            }

            string sOut = o.Process(map);
            Console.WriteLine("Case #{0}: {1}", iCase, sOut);


            //string[] sOut = o.ProcessMulti(roads,city);
            //Console.WriteLine("Case #{0}:", iCase);
            //for (int j = 0; j < sOut.Length; j++) {
            //    Console.WriteLine(sOut[j]);
            //}
        }

        if (bManual) Console.ReadKey();
    }

    static void M3() {

        string sLines = Console.ReadLine();
        bool bManual = sLines.StartsWith("m");
        if (bManual) sLines = sLines.Substring(1);
        int iCases = int.Parse(sLines);

        for (int iCase = 1; iCase <= iCases; iCase++) {

            EndlessKnight o = new EndlessKnight();

            string s = Console.ReadLine();
            int H = int.Parse( s.Split(' ')[0]);
            int W = int.Parse(s.Split(' ')[1]);
            int R = int.Parse(s.Split(' ')[2]);

            string[] Rs = new string[R];
            for (int i = 0; i < R; i++) {
                Rs[i] = Console.ReadLine();
            }

            string sOut = o.Process(H,W,Rs);
            Console.WriteLine("Case #{0}: {1}", iCase, sOut);


            //string[] sOut = o.ProcessMulti(roads,city);
            //Console.WriteLine("Case #{0}:", iCase);
            //for (int j = 0; j < sOut.Length; j++) {
            //    Console.WriteLine(sOut[j]);
            //}
        }

        if (bManual) Console.ReadKey();
    }

    static void M4() {

        string sLines = Console.ReadLine();
        bool bManual = sLines.StartsWith("m");
        if (bManual) sLines = sLines.Substring(1);
        int iCases = int.Parse(sLines);

        for (int iCase = 1; iCase <= iCases; iCase++) {

            //ClassName o = new ClassName();

            string s = Console.ReadLine();

            //string sOut = o.Process(a, b);
            //Console.WriteLine("Case #{0}: {1}", iCase, sOut);


            //string[] sOut = o.ProcessMulti(roads,city);
            //Console.WriteLine("Case #{0}:", iCase);
            //for (int j = 0; j < sOut.Length; j++) {
            //    Console.WriteLine(sOut[j]);
            //}
        }

        if (bManual) Console.ReadKey();
    }


    static void M1Old3() {

        string sLines = Console.ReadLine();
        bool bManual = sLines.StartsWith("m");
        if (bManual) sLines = sLines.Substring(1);
        int iCases = int.Parse(sLines);

        for (int iCase = 1; iCase <= iCases; iCase++) {

            CheatingBoolean o = new CheatingBoolean();

            string s = Console.ReadLine();
            int M = int.Parse(s.Split(' ')[0]);
            int V = int.Parse(s.Split(' ')[1]);

            bool[] bInterior = new bool[M];
            int[] val = new int[M];
            bool[] bAnd = new bool[M];
            bool[] changable = new bool[M];

            for (int i = 0; i < M/2; i++) {
                s = Console.ReadLine();
                bInterior[i] = true;
                val[i] = -1;
                bAnd[i] = s[0] == '1';
                changable[i] = s[2] == '1';
            }

            for (int i = M/2; i < M; i++) {
                bInterior[i] = false;
                val[i] = int.Parse(Console.ReadLine());
            }

            string sOut = o.Process(M,V,bInterior,val,bAnd,changable);
            Console.WriteLine("Case #{0}: {1}", iCase, sOut);


            //string[] sOut = o.ProcessMulti(roads,city);
            //Console.WriteLine("Case #{0}:", iCase);
            //for (int j = 0; j < sOut.Length; j++) {
            //    Console.WriteLine(sOut[j]);
            //}
        }

        if (bManual) Console.ReadKey();
    }

    static void M2Old3() {

        string sLines = Console.ReadLine();
        bool bManual = sLines.StartsWith("m");
        if (bManual) sLines = sLines.Substring(1);
        int iCases = int.Parse(sLines);

        for (int iCase = 1; iCase <= iCases; iCase++) {

            TriangleAreas o = new TriangleAreas();

            string s = Console.ReadLine();

            string sOut = o.Process(int.Parse(s.Split(' ')[0]), int.Parse(s.Split(' ')[1]), int.Parse(s.Split(' ')[2]));
            Console.WriteLine("Case #{0}: {1}", iCase, sOut);


            //string[] sOut = o.ProcessMulti(roads,city);
            //Console.WriteLine("Case #{0}:", iCase);
            //for (int j = 0; j < sOut.Length; j++) {
            //    Console.WriteLine(sOut[j]);
            //}
        }

        if (bManual) Console.ReadKey();
    }

    static void M3Old3() {

        string sLines = Console.ReadLine();
        bool bManual = sLines.StartsWith("m");
        if (bManual) sLines = sLines.Substring(1);
        int iCases = int.Parse(sLines);

        for (int iCase = 1; iCase <= iCases; iCase++) {

            //ClassName o = new ClassName();

            string s = Console.ReadLine();

            //string sOut = o.Process(a, b);
            //Console.WriteLine("Case #{0}: {1}", iCase, sOut);


            //string[] sOut = o.ProcessMulti(roads,city);
            //Console.WriteLine("Case #{0}:", iCase);
            //for (int j = 0; j < sOut.Length; j++) {
            //    Console.WriteLine(sOut[j]);
            //}
        }

        if (bManual) Console.ReadKey();
    }

    static void M4Old3() {

        string sLines = Console.ReadLine();
        bool bManual = sLines.StartsWith("m");
        if (bManual) sLines = sLines.Substring(1);
        int iCases = int.Parse(sLines);

        for (int iCase = 1; iCase <= iCases; iCase++) {

            PermRLE o = new PermRLE();

            string s = Console.ReadLine();
            int K = int.Parse(s);

            string sOut = o.Process(K, Console.ReadLine());
            Console.WriteLine("Case #{0}: {1}", iCase, sOut);


            //string[] sOut = o.ProcessMulti(roads,city);
            //Console.WriteLine("Case #{0}:", iCase);
            //for (int j = 0; j < sOut.Length; j++) {
            //    Console.WriteLine(sOut[j]);
            //}
        }

        if (bManual) Console.ReadKey();
    }

    static void M1Old2() {

        string sLines = Console.ReadLine();
        bool bManual = sLines.StartsWith("m");
        if (bManual) sLines = sLines.Substring(1);
        int N = int.Parse(sLines);

        for (int i = 0; i < N; i++) {

            CropTriangles o = new CropTriangles();

            string s = Console.ReadLine();

            string sOut = o.Process(s);
            Console.WriteLine("Case #{0}: {1}", i + 1, sOut);


            //string[] sOut = o.ProcessMulti(roads,city);
            //Console.WriteLine("Case #{0}:", i + 1);
            //for (int j = 0; j < sOut.Length; j++) {
            //    Console.WriteLine(sOut[j]);
            //}
        }

        if (bManual) Console.ReadKey();
    }

    static void M2Old2() {

        string sLines = Console.ReadLine();
        bool bManual = sLines.StartsWith("m");
        if (bManual) sLines = sLines.Substring(1);
        int N = int.Parse(sLines);

        for (int i = 0; i < N; i++) {

            NumberSets o = new NumberSets();

            string s = Console.ReadLine();

            string sOut = o.Process(s);
            Console.WriteLine("Case #{0}: {1}", i + 1, sOut);


            //string[] sOut = o.ProcessMulti(roads,city);
            //Console.WriteLine("Case #{0}:", i + 1);
            //for (int j = 0; j < sOut.Length; j++) {
            //    Console.WriteLine(sOut[j]);
            //}
        }

        if (bManual) Console.ReadKey();
    }

    static void M3Old2() {

        string sLines = Console.ReadLine();
        bool bManual = sLines.StartsWith("m");
        if (bManual) sLines = sLines.Substring(1);
        int N = int.Parse(sLines);

        for (int i = 0; i < N; i++) {

            MouseTrap o = new MouseTrap();
            int K = int.Parse(Console.ReadLine());
            string s = Console.ReadLine();

            string sOut = o.Process(K,s);
            Console.WriteLine("Case #{0}: {1}", i + 1, sOut);


            //string[] sOut = o.ProcessMulti(roads,city);
            //Console.WriteLine("Case #{0}:", i + 1);
            //for (int j = 0; j < sOut.Length; j++) {
            //    Console.WriteLine(sOut[j]);
            //}
        }

        if (bManual) Console.ReadKey();
    }
    
    static void M1Old() {

        string sLines = Console.ReadLine();
        bool bManual = sLines.StartsWith("m");
        if (bManual) sLines = sLines.Substring(1);
        int N = int.Parse(sLines);

        for (int i = 0; i < N; i++) {

            MinimumScalarProduct o = new MinimumScalarProduct();

            string s2 = Console.ReadLine();
            int nn = int.Parse(s2);
            int[] a = new int[nn];
            int[] b = new int[nn];
            string[] s3 = Console.ReadLine().Split(' ');
            for (int j = 0; j < nn; j++) {
                a[j] = int.Parse(s3[j]);
            }
            s3 = Console.ReadLine().Split(' ');
            for (int j = 0; j < nn; j++) {
                b[j] = int.Parse(s3[j]);
            }

            string sOut = o.Process(a, b);
            //string sOut = o.ProcessPair(Console.ReadLine(), Console.ReadLine());
            Console.WriteLine("Case #{0}: {1}", i + 1, sOut);

        }

        if (bManual) Console.ReadKey();
    }

    static void M2Old() {

        string sLines = Console.ReadLine();
        bool bManual = sLines.StartsWith("m");
        if (bManual) sLines = sLines.Substring(1);
        int N = int.Parse(sLines);

        for (int i = 0; i < N; i++) {

            Milkshakes o = new Milkshakes();

            string s = Console.ReadLine();
            int F = int.Parse(s);
            int C = int.Parse(Console.ReadLine());
            string[] cust = new string[C];
            for (int j = 0; j < C; j++) {
                cust[j] = Console.ReadLine();
            }

            string sOut = o.Process(F, cust);
            Console.WriteLine("Case #{0}: {1}", i + 1, sOut);


            //string[] sOut = o.ProcessMulti(roads,city);
            //Console.WriteLine("Case #{0}:", i + 1);
            //for (int j = 0; j < sOut.Length; j++) {
            //    Console.WriteLine(sOut[j]);
            //}
        }

        if (bManual) Console.ReadKey();
    }

    static void M3Old() {

        string sLines = Console.ReadLine();
        bool bManual = sLines.StartsWith("m");
        if (bManual) sLines = sLines.Substring(1);
        int N = int.Parse(sLines);

        for (int i = 0; i < N; i++) {

            //var o = new MinimumScalarProduct();

            //string sOut = o.Process(a, b);
            //Console.WriteLine("Case #{0}: {1}", i + 1, sOut);


            //string[] sOut = o.ProcessMulti(roads,city);
            //Console.WriteLine("Case #{0}:", i + 1);
            //for (int j = 0; j < sOut.Length; j++) {
            //    Console.WriteLine(sOut[j]);
            //}
        }

        if (bManual) Console.ReadKey();
    }

    static void M0() {

        string sLines = Console.ReadLine();
        bool bManual = sLines.StartsWith("m");
        if (bManual) sLines = sLines.Substring(1);
        int iCases = int.Parse(sLines);

        for (int iCase = 1; iCase <= iCases; iCase++) {

            //ClassName o = new ClassName();

            string s = Console.ReadLine();

            //string sOut = o.Process(a, b);
            //Console.WriteLine("Case #{0}: {1}", iCase, sOut);


            //string[] sOut = o.ProcessMulti(roads,city);
            //Console.WriteLine("Case #{0}:", iCase);
            //for (int j = 0; j < sOut.Length; j++) {
            //    Console.WriteLine(sOut[j]);
            //}
        }

        if (bManual) Console.ReadKey();
    }
}
