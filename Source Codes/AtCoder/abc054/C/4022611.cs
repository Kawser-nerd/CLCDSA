using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Atcoder
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] NM = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            Node[] nodes = new Node[NM[0]];
            for (int i = 0; i < NM[0]; i++)
            {
                nodes[i] = new Node();
            }

            for (int i = 0; i < NM[1]; i++)
            {
                int[] edge = Console.ReadLine().Split(' ').Select(int.Parse).Select(x=>x-1).ToArray();
                nodes[edge[0]].number = edge[0];
                nodes[edge[0]].next.Add(edge[1]);
                nodes[edge[1]].number = edge[1];
                nodes[edge[1]].next.Add(edge[0]);

            }
            Person person = new Person(0, NM[0]);
            person.history[0] = true;
            Queue<Person> people = new Queue<Person>();
            people.Enqueue(person);
            int output = 0;
            while (people.Count > 0)
            {
                Person tuginokata = people.Dequeue();
                bool isFinished = true;
                for (int i = 0; i < tuginokata.history.Length; i++)
                {
                    isFinished = isFinished && tuginokata.history[i];
                }
                if (isFinished) output++;
                else
                {
                    List<int> next_choice = nodes[tuginokata.You_are_here].next;
                    for (int i = 0; i < next_choice.Count; i++)
                    {
                        Person next_generation = tuginokata.Clone();
                        if (next_generation.history[next_choice[i]] == false)
                        {
                            //??????????
                            next_generation.history[next_choice[i]] = true;
                            //?????????????
                            next_generation.You_are_here = next_choice[i];
                            //????
                            people.Enqueue(next_generation);
                            //?????
                        }
                    }
                }

            }
            ;
            Console.WriteLine(output);
        }



    }
    class Node
    {
        public int number;
        public List<int> next;
        public Node(int number)
        {
            this.number = number;
            this.next = new List<int>();
        }
        public Node()
        {
            this.number = 0;
            this.next = new List<int>();
        }
    }


    class Person
    {
        public int You_are_here;
        public bool[] history;
        public Person(int place, int N)
        {
            this.You_are_here = place;
            this.history = new bool[N];
        }
        public Person Clone()
        {
            Person output = new Person(0,this.history.Length);
            output.You_are_here = this.You_are_here;
            output.history = (bool[])this.history.Clone();
            return output;
        }
    }

}