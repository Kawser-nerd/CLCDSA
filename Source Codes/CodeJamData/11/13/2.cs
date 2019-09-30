using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Pseudo
{
    class Program
    {        
        
        static void Main(string[] args)
        {
            int cases = int.Parse(Console.ReadLine());

            for (int i = 0; i < cases; i++)
            {
                List<Card> hand = new List<Card>();
                List<Card> deck = new List<Card>();
                int handCards = int.Parse(Console.ReadLine());
                for (int j = 0; j < handCards; j++)
                {
                    String[] line = Console.ReadLine().Split(' ');
                    hand.Add(new Card(int.Parse(line[0]), int.Parse(line[1]), int.Parse(line[2])));
                }
                int deckCards = int.Parse(Console.ReadLine());
                for (int j = 0; j < deckCards; j++)
                {
                    String[] line = Console.ReadLine().Split(' ');
                    deck.Add(new Card(int.Parse(line[0]), int.Parse(line[1]), int.Parse(line[2])));
                }

                Console.Error.Write("Case #{0}: ({1}, {2}) = ", i + 1, handCards, deckCards);

                int answer = Solve(hand, deck);
                Console.Error.WriteLine(answer);

                Console.WriteLine("Case #{0}: {1}", i + 1, answer);
            }
        }

        static int Solve(List<Card> hand, List<Card> deck)
        {
            return Solve(hand, deck, 0, 1);
        }

        static int Solve(List<Card> hand, List<Card> deck, int score, int turns)
        {
            if (hand.Count == 0 || turns == 0)
                return score;

            List<Card> h = new List<Card>(hand);
            List<Card> d = new List<Card>(deck);

            if (h.Any(c => c.turns > 0))
            {
                //play the first card with turns > 0
                for (int i = 0; i < h.Count; i++)
                    if (h[i].turns > 0)
                    {
                        score += h[i].score;
                        turns += h[i].turns - 1;
                        for (int c = 0; c < h[i].cards && d.Count > 0; c++)
                        {
                            h.Add(d[0]);
                            d.RemoveAt(0);
                        }
                        h.RemoveAt(i--);
                    }
            }

            if (h.Count == 0)
                return score;

            h.Sort();

            //either we play the next card, or we don't.
            int scorePlay = score + h[0].score;
            int newCards = h[0].cards;
            int cardScore = h[0].score;
            h.RemoveAt(0);

            List<Card> skipHand = h.SkipWhile(c => c.score <= cardScore).ToList();
            int skipScore = Solve(skipHand, d, score, turns);
            for (int j = 0; j < newCards && d.Count > 0; j++)
            {
                h.Add(d[0]);
                d.RemoveAt(0);
            }
            int playScore = Solve(h, d, scorePlay, turns - 1);

            return Math.Max(skipScore, playScore);
            
        }
    }

    class Card : IComparable<Card>
    {
        public int cards;
        public int score;
        public int turns;
        public Card(int c, int s, int t)
        {
            cards = c;
            score = s;
            turns = t;
        }

        public override String ToString()
        {
            return String.Format("({0}, {1}, {2})", cards, score, turns);
        }

        #region IComparable<Card> Members

        public int CompareTo(Card other)
        {
            if (cards != other.cards)
                return -cards.CompareTo(other.cards);
            if (score != other.score)
                return -score.CompareTo(other.score);
            return -turns.CompareTo(other.turns);
        }

        #endregion
    }
}
