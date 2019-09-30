using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

// Julgodis 2015
namespace Q2015_C
{
    class TestCase
    {
        public int L;
        public int X;

        public String Base;
        public String Real;
    }

    enum Type { 
        I,
        J,
        K,
        ONE
    }

    class Value
    {
        public Type Type;
        public bool Signed;

        public Value(Type A, bool B) {
            Type = A;
            Signed = B;
        }

        public override string ToString()
        {
            return (Signed ? "-" : "") + Enum.GetName(typeof(Type), Type);
        }
    }

    class Program
    {
        static Value X(Value A, Value B) 
        {
            bool sign = (A.Signed || B.Signed) && !(A.Signed && B.Signed);

            if (A.Type == B.Type)
                return new Value(Type.ONE, (A.Type == Type.ONE ? sign : !sign));

            if (A.Type == Type.ONE)
                return new Value(B.Type, sign);

            if (B.Type == Type.ONE)
                return new Value(A.Type, sign);

            if (A.Type == Type.I) { 
                if(B.Type == Type.J)
                    return new Value(Type.K, sign);
                else if(B.Type == Type.K)
                    return new Value(Type.J, !sign);
            }

            if (A.Type == Type.J)
            {
                if (B.Type == Type.I)
                    return new Value(Type.K, !sign);
                else if (B.Type == Type.K)
                    return new Value(Type.I, sign);
            }

            if (A.Type == Type.K)
            {
                if (B.Type == Type.I)
                    return new Value(Type.J, sign);
                else if (B.Type == Type.J)
                    return new Value(Type.I, !sign);
            }

            throw new Exception();
        }

        static Value IN(char c) {
            if (c == 'I' || c == 'i')
                return new Value(Type.I, false);

            if (c == 'J' || c == 'j')
                return new Value(Type.J, false);

            if (c == 'K' || c == 'k')
                return new Value(Type.K, false);

            throw new Exception();
        }

        static bool Solve(TestCase testCase)
        {
            int index = 1;
            int subsetType = 0;
            String str = testCase.Real;

            // Special cases
            if (str.Length < 3)
                return false;

            if (str.Length == 3)
                return str == "ijk";

            if (testCase.L == 1)
                return false;

            Value prev = IN(str[0]);
            while (true) {

                if (index >= str.Length)
                    return false;

                Value value = IN(str[index++]);
                Value product = X(prev, value);
                prev = product;

                if (product.Type == (Type)subsetType 
                    && !product.Signed) 
                {
                    subsetType++;

                    if (subsetType >= 2)
                    {

                        prev = IN(str[index++]);
                        while (index < str.Length) {
                            value = IN(str[index++]);
                            product = X(prev, value);
                            prev = product;
                        }

                        return (prev.Type == (Type)subsetType && !prev.Signed);
                    }
                    prev = IN(str[index++]);
                }
            
            }
        }

        static void Main(string[] args)
        {
            var input = args[0];
            var output = args[1];

            var fileData = File.ReadAllLines(input);
            var cases = ParseInput(fileData);

            int i = 0;
            var data = "";
            foreach (var testCase in cases)
            {
                var result = Solve(testCase);

                Console.WriteLine("Case #{0}: {1}", i + 1, result);
                data += "Case #" + (i + 1) + ": " + (result?"YES":"NO") + "\n";
                i++;
            }

            File.WriteAllText(output, data);
            return;
        }

        static TestCase[] ParseInput(String[] lines)
        {
            var cases = new List<TestCase>();

            int T = Int32.Parse(lines[0]);
            int C = 1;
            for (int i = 0; i < T; i++)
            {
                var testCase = new TestCase();

                var data = lines[C++].Split(' ');
                var L = Int32.Parse(data[0]);
                var X = Int32.Parse(data[1]);
                var str = lines[C++];

                testCase.L = L;
                testCase.X = X;
                testCase.Base = str;

                for (int j = 0; j < X; j++)
                    testCase.Real += testCase.Base;

                cases.Add(testCase);
            }

            return cases.ToArray();
        }
    }
}
