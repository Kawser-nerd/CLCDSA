using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;

public class A
{
    public static void Main(string[] args)
    {
        Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        int CASES = int.Parse(Console.ReadLine());
        for (int CASE = 1; CASE <= CASES; CASE++)
        {
            Console.WriteLine("Case #" + CASE + ":");
            int L = int.Parse(Console.ReadLine());
            string tree = "";
            for (int i = 0; i < L; i++)
                tree += Console.ReadLine() + " ";
            Tree t = new Tree(ref tree);

            int A = int.Parse(Console.ReadLine());
            for (int i = 0; i < A; i++)
            {
                Animal a = new Animal(Console.ReadLine());
                Console.WriteLine(t.getProb(a).ToString("0.0000000"));
            }
        }
    }

    public class Tree
    {
        public double prob;
        public string feature;
        public Tree left, right;

        public Tree(ref string data)
        {
            int i = 0;
            while (char.IsWhiteSpace(data[i])) i++;
            if (data[i] != '(')
                throw new Exception();
            i++;
            while (char.IsWhiteSpace(data[i])) i++;
            int nextWhitespace = i;
            while(!char.IsWhiteSpace(data[nextWhitespace]) && data[nextWhitespace] != ')')
                nextWhitespace++;
            prob = double.Parse(data.Substring(i, nextWhitespace - i));
            i = nextWhitespace;
            while (char.IsWhiteSpace(data[i]))
                i++;

            if (data[i] == ')')
            {
                i++;
                data = data.Substring(i);
            }
            else
            {
                nextWhitespace = i;
                while (!char.IsWhiteSpace(data[nextWhitespace]))
                    nextWhitespace++;
                feature = data.Substring(i, nextWhitespace - i);
                i = nextWhitespace;

                data = data.Substring(i);
                left = new Tree(ref data);
                right = new Tree(ref data);
                i = 0;
                while (char.IsWhiteSpace(data[i])) i++;
                if (data[i] != ')')
                    throw new Exception();
                i++;
                data = data.Substring(i);
            }
        }

        public double getProb(Animal a)
        {
            if (feature == null)
                return prob;
            if (a.hasFeature(feature))
                return left.getProb(a) * prob;
            else
                return right.getProb(a) * prob;
        }
    }

    public class Animal
    {
        public string[] features;

        public Animal(string line)
        {
            string[] parts = line.Split();
            features = new string[parts.Length - 2];
            for (int i = 0; i < features.Length; i++)
                features[i] = parts[i + 2];
        }

        public bool hasFeature(string feature)
        {
            return Array.IndexOf(features, feature) > -1;
        }
    }
}
