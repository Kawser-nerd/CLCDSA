using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace r1c
{
    struct card
    {
        public int c;
        public int s;
        public int t;
        public card(int c,int s,int t)
        {
            this.c = c;
            this.s = s;
            this.t = t;
        }
    }

    class Program
    {
        static int simulate(List<card> hand1, Queue<card> deck1, int turn)
        {
            if (turn == 0 || hand1.Count == 0)
            {
                return 0;
            }

            List<card> hand = new List<card>(hand1);
            Queue<card> deck = new Queue<card>(deck1);


            //for small
            int score = 0;

            for (int i = 0; i < hand.Count; i++)
            {
                card card = hand[i];

                if (card.t > 0)
                {
                    play(hand, deck, i, ref score, ref turn);
                    return score + simulate(hand, deck, turn);
                }
            }

            //no turn card
            //Console.WriteLine("test");
            //in case no draw
            int turn2 = turn;
            while(turn2 > 0 && hand.Count > 0)
            {
                int ms = -1;
                int msi = -1;
                for (int i = 0; i < hand.Count; i++)
                {
                    card card = hand[i];

                    if (ms < card.s)
                    {
                        ms = card.s;
                        msi = i;
                    }
                }
                int dummy = 0;
                int sss = 0;
                play(hand, deck, msi, ref sss, ref dummy);
                score += sss;
                turn2--;
            }
            //incase draw 1 card
            {
                hand = new List<card>(hand1);
                deck = new Queue<card>(deck1);

                int ms = -1;
                int msi = -1;
                for (int i = 0; i < hand.Count; i++)
                {
                    card card = hand[i];
                    
                    if (card.c == 1 && ms < card.s)
                    {
                        ms = card.s;
                        msi = i;
                    }
                }
                if (msi == -1)
                    return score;
                int dummy = 0;
                int sss = 0;
                play(hand, deck, msi, ref sss, ref dummy);
                int s2 = sss + simulate(hand, deck, turn - 1);
                if (s2 > score)
                    score = s2;
            }

            return score;
        }

        static void draw(List<card> hand, Queue<card> deck, int count)
        {
            for (int i = 0; i < count; i++)
            {
                if (deck.Count > 0)
                {
                    card c = deck.Dequeue();
                    hand.Add(c);
                }
            }
        }

        static void play(List<card> hand, Queue<card> deck, int num,ref int score,ref int turn)
        {
            card c = hand[num];
            hand.RemoveAt(num);

            if (c.c > 0)
                draw(hand, deck, c.c);
            score += c.s;
            turn += c.t - 1;
        }

        static void Main(string[] args)
        {

            int z = int.Parse(Console.In.ReadLine());

            TextWriter writer = Console.Out;
            //TextWriter writer = new StreamWriter("out.txt");


            for (int i = 0; i < z; i++)
            {
                List<card> hand = new List<card>();
                Queue<card> deck = new Queue<card>();

                int n = int.Parse(Console.In.ReadLine());

                for (int j = 0; j < n; j++)
                {
                    string[] input = Console.In.ReadLine().Split(' ');

                    int c = int.Parse(input[0]);
                    int s = int.Parse(input[1]);
                    int t = int.Parse(input[2]);
                    card ca = new card(c, s, t);

                    hand.Add(ca);
                }
                int m = int.Parse(Console.In.ReadLine());
                for (int j = 0; j < m; j++)
                {
                    string[] input = Console.In.ReadLine().Split(' ');

                    int c = int.Parse(input[0]);
                    int s = int.Parse(input[1]);
                    int t = int.Parse(input[2]);
                    card ca = new card(c, s, t);

                    deck.Enqueue(ca);
                }

                //Console.WriteLine("" + n + " " + m);

                int score = simulate(hand, deck,1);

                writer.WriteLine("Case #" + (i + 1) + ": " + score);
            }
        }
    }
}
