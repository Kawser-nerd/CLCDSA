using System;
namespace MyConsoleAppPoisonousCookies
{ /*
    public class Position // ?????????
    {
        private int num;
        private int x_pos;
        private int y_pos;
        private int checkPosition;
        private int withInRange;
        //
        // ????
        //
        public int Num
        {
            set { num = value; }
            get { return num; }
        }
        public int X_pos
        {
            set { x_pos = value; }
            get { return x_pos; }
        }
        public int Y_pos
        {
            set { y_pos = value; }
            get { return y_pos; }
        }
        public int CheckPosition
        {
            set { checkPosition = value; }
            get { return checkPosition; }
        }
        public int WithInRange
        {
            set { withInRange = value; }
            get { return withInRange; }
        }

        public Position(int num, int x_pos, int y_pos, int checkPosition, int withInRange)
        {
            this.Num = num;
            this.X_pos = x_pos;
            this.Y_pos = y_pos;
            CheckPosition = checkPosition;
            WithInRange = withInRange;
        }
    }
    //
    class Program
    {
        //private static bool Checker { get; set; } = false;
        //private static bool Check_dream { get; set; } = true;
        //private static bool Check_dreamer { get; set; } = true;
        //private static bool Check_erase { get; set; } = true;
        //private static bool Check_eraser { get; set; } = true;
        
            public struct Position // ?????????
            {
                public int num;
                public int x_pos;
                public int y_pos;
                public int CheckPosition;// true 1 false 0?????????????????????????
                public int WithInRange; // true 1 false 0?????????????????????
            }
        

 */
 //
 // Poisonous Cookies
 //
 class Program
    {
        static void Main(string[] args)
        {
            //
            // ??
            //
            /*
                    // ?????
                    int a = int.Parse(Console.ReadLine());
                    // ?????????????
                    string[] input = Console.ReadLine().Split(' ');
                    int b = int.Parse(input[0]);
                    int c = int.Parse(input[1]);
                    // ??????
                    string s = Console.ReadLine();
                    //??
                    Console.WriteLine((a+b+c) + " " + s);

            string[] input = Console.ReadLine().Split(' '); // 10000??5000??1000?
            int num = int.Parse(input[0]); // ?????
            int amount = int.Parse(input[1]); // ????

            int man = 0;
            int gosen = 0;
            int sen = 0;
            int gokei = 0;

            int k;
            */

            //
            // ??
            //
            string[] input = Console.ReadLine().Split(' ');
            int cookie_a = int.Parse(input[0]); // A????????
            int cookie_b = int.Parse(input[1]); // B?????????
            int cookie_c = int.Parse(input[2]); // C?????????

            int max;//??????????????
            int delicious;//??????????

            if (cookie_a+cookie_b >= cookie_c) // ????????????????
            {
                max = cookie_a + cookie_b+cookie_c;
                delicious = cookie_b + cookie_c;
            }
            else // ??????????????????????????
            {
                max = (cookie_a + cookie_b)*2 + 1;
                delicious = max-cookie_a;
            }
            //
            //int n = int.Parse(Console.ReadLine());// ???????
            //Position[] pos = new Position[n];// ????????pos[i]?????
            //for (int i = 0; i < n; i++)
            //{
            //    string[] input = Console.ReadLine().Split(' ');
            //    pos[i] = new Position(int.Parse(input[0]), int.Parse(input[1]), int.Parse(input[2]), 1, 1);
            //}
            //
            /*
            for (int j = 0; j < n; j++)
            {
                pos[j].CheckPosition = 0;
                pos[j].WithInRange = 0;
                //???????(x_pos+y_pos)????????????
                if (((pos[j].Num % 2) == 0 && ((pos[j].X_pos + pos[j].Y_pos) % 2) == 0))

                {
                    pos[j].CheckPosition = 1;
                }
                //???????(x_pos+y_pos)????????????
                if (((pos[j].Num % 2) == 1 && ((pos[j].X_pos + pos[j].Y_pos) % 2) == 1))
                {
                    pos[j].CheckPosition = 1;
                }
                //???????????????
                if ((pos[j].X_pos <= pos[j].Num) &&
                    (pos[j].Y_pos <= pos[j].Num) &&
                    (pos[j].X_pos + pos[j].Y_pos <= pos[j].Num))
                {
                    pos[j].WithInRange = 1;
                }
                else
                {
                    pos[j].WithInRange = 0;
                }
            }
            */
            //
            // ??????????CheckPosition?WithInRange???????????
            //???????(false)????????No??????????????
            //
            /*
            int CheckPosition = 1;
            int WithInRange = 1;
            for (int k = 0; k < n; k++)
            {
                CheckPosition *= pos[k].CheckPosition;
                WithInRange *= pos[k].WithInRange;
            }
            */
            //
            // ??
            //
            /*
            if ((CheckPosition == 1) && (WithInRange == 1))
            {
                Console.WriteLine("Yes");
            }
            else
            {
                Console.WriteLine("No");
            }
            */
            Console.WriteLine(delicious);
        }
    }
}




    /*
                    string dream = "dream";
                    string dreamer = "dreamer";
                    string erase = "erase";
                    string eraser = "eraser";

                    bool Check_dream = true;
                    bool Check_dreamer = true;
                    bool Check_erase = true;
                    bool Check_eraser = true;

                    string s = Console.ReadLine();
                    //Console.WriteLine(s);

                    while ((Check_dream == true) || (Check_dreamer == true) || (Check_erase == true) || (Check_eraser == true))
                    {
                        if (s.EndsWith(dreamer))
                        {
                            s = s.Remove(s.Length - 7, 7);
                            //Console.WriteLine(s);
                            Check_dreamer = true;
                        }
                        else
                        {
                            Check_dreamer = false;
                        }
                        if (s.EndsWith(dream))
                        {
                            s = s.Remove(s.Length - 5, 5);
                            //Console.WriteLine(s);
                            Check_dream = true;
                        }
                        else
                        {
                            Check_dream = false;
                        }
                        if (s.EndsWith(eraser))
                        {
                            s = s.Remove(s.Length - 6, 6);
                            //Console.WriteLine(s);
                            Check_eraser = true;
                        }
                        else
                        {
                            Check_eraser = false;
                        }
                        if (s.EndsWith(erase))
                        {
                            s = s.Remove(s.Length - 5, 5);
                            //Console.WriteLine(s);
                            Check_erase = true;
                        }
                        else
                        {
                            Check_erase = false;
                        }
                    }
                    //
                    if (s.Length == 0)
                    {
                        Console.WriteLine("YES");
                    }
                    else
                    {
                        Console.WriteLine("NO");
                    }
                    */


    /*
    for (int i = 0; i < N; i++)
    {
        //card[i] = int.Parse(input[i]); // ????????????????
        radius[i] = int.Parse(Console.ReadLine());
    }
    */
    //
    // ???
    //
    //Array.Sort(card); // ????????
    //Array.Reverse(card); // ???????
    //Array.Sort(radius);
    /*
    for (int j = 0; j < radius.Length - 1; j++)
    {
        if (radius[j] < radius[j + 1])
        {
            count++;
        }

    }
    */

    //
    // ??
    //
    //Console.WriteLine("Alice"+alice);
    //Console.WriteLine("Bob"+bob);
    //Console.WriteLine(count);

    //Console.WriteLine("[{0}]",string.Join(", ",card));