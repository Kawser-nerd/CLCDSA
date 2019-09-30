using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections.Specialized;

namespace GoogleCodeJamRound1_2
{
    class Program
    {
        static void Main(string[] args)
        {
            char[] myChars = { ' ' };
            string[] fileLines = File.ReadAllLines(@"D:\inputs\round1\B-large.in");
            TextWriter outputFile = new StreamWriter(@"D:\outputs\2-large.txt");

            int numTimes = int.Parse(fileLines[0]);
            int count = 1;
            for (int i = 1; i < fileLines.Length; i++)
            {
                bool impossible = false;
                List<int> flavorArray = new List<int>();
                List<Customer> customerArray = new List<Customer>();
                int numFlavors = int.Parse(fileLines[i++]);
                int numCustomers = int.Parse(fileLines[i++]);

                for (int j = 1; j <= numFlavors; j++)
                {
                    //start with unmalted
                    flavorArray.Add(0);
                }
                for (int j = 0; j < numCustomers; j++)
                {
                    bool garbage = false;
                    customerArray.Add(new Customer(fileLines[i++]));
                    impossible = impossible | integrateCustomer(customerArray[customerArray.Count - 1], flavorArray, out garbage);
                }
                for (int j = 0; j < numCustomers; j++)
                {
                    bool changed = false;
                    impossible = impossible | integrateCustomer(customerArray[j], flavorArray, out changed);
                    if (changed)
                        j = -1;
                }
                if (impossible)
                {
                    Console.WriteLine("Case #" + count.ToString() + ": IMPOSSIBLE");
                    outputFile.WriteLine("Case #" + count.ToString() + ": IMPOSSIBLE");
                }
                else
                {
                    Console.Write("Case #" + count.ToString() + ": ");
                    outputFile.Write("Case #" + count.ToString() + ": ");
                    for (int j = 0; j < flavorArray.Count; j++)
                    {
                        Console.Write(flavorArray[j].ToString() + " ");
                        outputFile.Write(flavorArray[j].ToString() + " ");
                    }
                    Console.Write("\r\n");
                    outputFile.Write("\r\n");
                }
                i--;
                count++;
            }
            outputFile.Close();
        }
        //returns true for impossible, false for possible
        public static bool integrateCustomer(Customer newCust, List<int> myFlavors, out bool changed)
        {
            bool matchFound = false;
            bool maltedPossible = false;
            int maltedIndex = 0;
            for (int i = 0; i < newCust.flavors.Count; i++)
            {
                if (myFlavors[newCust.flavors[i] - 1] == newCust.malted[i])
                    matchFound = true;
                if ((myFlavors[newCust.flavors[i] - 1] == 0) && (newCust.malted[i] == 1))
                {
                    maltedPossible = true;
                    maltedIndex = i;
                }
            }
            if (matchFound)
            {
                changed = false;
                return false;
            }
            else if (maltedPossible)
            {
                myFlavors[newCust.flavors[maltedIndex] - 1] = 1;
                changed = true;
                return false;
            }
            else
            {
                changed = false;
                return true;
            }
        }
        //        char[] myChars = { ' ', ':' };
        //        string[] splits = myTimes.Split(myChars);
    }
    class Customer
    {
        public int numFlavors;
        public List<int> flavors;
        public List<int> malted;
        public Customer(string custLine)
        {
            char[] myChars = { ' ' };
            string[] myStrings = custLine.Split(myChars);
            numFlavors = int.Parse(myStrings[0]);

            flavors = new List<int>();
            malted = new List<int>();
            int j = 1;
            for (int i = 0; i < numFlavors; i++)
            {
                int first = int.Parse(myStrings[j++]);
                int second = int.Parse(myStrings[j++]);
                flavors.Add(first);
                malted.Add(second);
            }
        }
    }
}
