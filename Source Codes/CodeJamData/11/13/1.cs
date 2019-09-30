using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Text.RegularExpressions;

namespace Cardgame
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader inFile = new StreamReader("test.in");
            StreamWriter outFile = new StreamWriter("out.txt");

            int num_cases = Convert.ToInt32(inFile.ReadLine());

            int cardsInHand;
            int cardsInDeck;

            for (int _case = 0; _case < num_cases; _case++)
            {
                cardsInHand = Convert.ToInt32(inFile.ReadLine());
                List<Card> Hand = new List<Card>();

                for (int _hand = 0; _hand < cardsInHand; _hand++)
                {
                    string line = inFile.ReadLine();
                    int c = Convert.ToInt32(line.Split(' ')[0]);
                    int s = Convert.ToInt32(line.Split(' ')[1]);
                    int t = Convert.ToInt32(line.Split(' ')[2]);

                    Hand.Add(new Card(c, s, t));
                }

                cardsInDeck = Convert.ToInt32(inFile.ReadLine());
                List<Card> Deck = new List<Card>();

                for (int _deck = 0; _deck < cardsInDeck; _deck++)
                {
                    string line = inFile.ReadLine();
                    int c = Convert.ToInt32(line.Split(' ')[0]);
                    int s = Convert.ToInt32(line.Split(' ')[1]);
                    int t = Convert.ToInt32(line.Split(' ')[2]);

                    Deck.Add(new Card(c, s, t));
                }

                int total = MaxScore(Hand, Deck, 1);

                outFile.WriteLine("Case #" + (_case + 1) + ": " + total);
            }

            
            outFile.Flush();
            outFile.Close();

        }

        public static int MaxScore(List<Card> Hand, List<Card> Deck, int turns)
        {
            int score = 0;

            while (Hand.Count > 0 && turns > 0)
            {
                Hand.Sort(CompareTurns);
                if (Hand[0].t > 0)
                {
                    score += Hand[0].s;
                    turns += Hand[0].t;
                    for (int i = 0; i < Hand[0].c; i++)
                    {
                        if (Deck.Count > 0)
                        {
                            Hand.Add(Deck[0]);
                            Deck.RemoveAt(0);
                        }
                    }
                    Hand.RemoveAt(0);
                    turns--;
                }
                else
                {
                    List<Card> HandsAlpha = new List<Card>(Hand);
                    List<Card> DeckAlpha = new List<Card>(Deck);

                    HandsAlpha.Sort(CompareScore);
                    int scoreAlpha =  score + HandsAlpha[0].s;
                    for (int i = 0; i < HandsAlpha[0].c; i++)
                    {
                        if (DeckAlpha.Count > 0)
                        {
                            HandsAlpha.Add(Deck[0]);
                            DeckAlpha.RemoveAt(0);
                        }
                    }
                    HandsAlpha.RemoveAt(0);
                    scoreAlpha += MaxScore(HandsAlpha, DeckAlpha, turns-1);

                    if (DeckAlpha.Count == 0 || turns > (DeckAlpha.Count + HandsAlpha.Count))
                        return scoreAlpha;


                    List<Card> HandsBeta = new List<Card>(Hand);
                    List<Card> DeckBeta = new List<Card>(Deck);

                    HandsBeta.Sort(CompareCards);
                    int scoreBeta =  score + HandsBeta[0].s;
                    for (int i = 0; i < HandsBeta[0].c; i++)
                    {
                        if (DeckBeta.Count > 0)
                        {
                            HandsBeta.Add(Deck[0]);
                            DeckBeta.RemoveAt(0);
                        }
                    }
                    HandsBeta.RemoveAt(0);
                    scoreBeta += MaxScore(HandsBeta, DeckBeta, turns-1);

                    return (scoreAlpha > scoreBeta ? scoreAlpha : scoreBeta);
                }
            }

            return score;
        }


        private static int CompareCards(Card x, Card y)
        {
            return (-x.c.CompareTo(y.c) != 0 ? -x.c.CompareTo(y.c) : -x.s.CompareTo(y.s));
        }

        private static int CompareScore(Card x, Card y)
        {
            return (-x.s.CompareTo(y.s) != 0 ? -x.s.CompareTo(y.s) : -x.c.CompareTo(y.c));
        }

        private static int CompareTurns(Card x, Card y)
        {
            return -x.t.CompareTo(y.t);
        }

    }

    class Card
    {
        public int c;
        public int s;
        public int t;

        public Card(int _c, int _s, int _t)
        {
            c = _c;
            s = _s;
            t = _t;
        }
    }
}
