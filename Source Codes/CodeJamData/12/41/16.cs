using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;



#region Hide
static public class Serializer
{
    static public void SerializeObject(string filename, object

objectToSerialize)
    {
        Stream stream = File.Open(filename, FileMode.Create);
        BinaryFormatter bFormatter = new BinaryFormatter();
        bFormatter.Serialize(stream, objectToSerialize);
        stream.Close();
    }

    static public object DeSerializeObject(string filename)
    {
        object objectToSerialize;
        Stream stream = File.Open(filename, FileMode.Open);
        BinaryFormatter bFormatter = new BinaryFormatter();
        objectToSerialize =
           (object)bFormatter.Deserialize(stream);
        stream.Close();
        return objectToSerialize;
    }
}

class Reader : System.IO.StreamReader
{


    public Reader(string path) : base(path) { }

    public int ReadInt()
    {
        if (this.EndOfStream)
            throw new Exception("end of stream");
        bool minus = false;
        while (!this.EndOfStream && !char.IsDigit((char)this.Peek()))
        {
            minus = this.Peek() == '-';
            this.Read();
        }
        int r = 0;
        while (!this.EndOfStream && char.IsDigit((char)this.Peek()))
        {
            r *= 10;
            r += this.Read() - '0';
        }
        if (minus)
            r *= -1;
        return r;
    }
    public long ReadLong()
    {
        if (this.EndOfStream)
            throw new Exception("end of stream");
        bool minus = false;
        while (!this.EndOfStream && !char.IsDigit((char)this.Peek()))
        {
            minus = this.Peek() == '-';
            this.Read();
        }
        long r = 0;
        while (!this.EndOfStream && char.IsDigit((char)this.Peek()))
        {
            r *= 10;
            r += this.Read() - '0';
        }
        if (minus)
            r *= -1;
        return r;
    }
    public char ReadChar()
    {
        if (this.EndOfStream)
            throw new Exception("end of stream");
        return (char)this.Read();
    }
    public string ReadWord()
    {
        if (this.EndOfStream)
            throw new Exception("end of stream");
        while (!this.EndOfStream && char.IsWhiteSpace((char)this.Peek()))
        {
            this.Read();
        }
        StringBuilder sb = new StringBuilder();

        while (!this.EndOfStream && !char.IsWhiteSpace((char)this.Peek()))
        {
            sb.Append((char)this.Read());
        }
        return sb.ToString();
    }
}
#endregion


class Program
{

    class A:IComparable<A>
    {
        public int d, len;
        public int s = int.MaxValue;
        public A(int d,int len)
        {
            this.d=d;
            this.len=len;
        }

        int IComparable<A>.CompareTo(A other)
        {
            return this.d.CompareTo(other.d);
        }
    }


    static void Main(string[] args)
    {
        Reader sr = new Reader("C:\\test\\in.in");
        StreamWriter sw = new StreamWriter("C:\\test\\out.out");
        sw.AutoFlush = true;
        int n = int.Parse(sr.ReadLine());
        Console.WriteLine(n);
        for (int i = 0; i < n; i++)
        {
            sw.WriteLine("Case #" + (i + 1).ToString() + ": " + Solution(sr));
            Console.WriteLine(i);
        }
        sw.Close();
        sr.Close();
        Console.WriteLine("Finished");
        Console.ReadLine();
    }

    static string Solution(Reader sr)
    {
        int N = int.Parse(sr.ReadLine());
        List<A> D=new List<A>();
        for (int i = 0; i < N; i++)
        {
            string[] t = sr.ReadLine().Split(' ');
            D.Add(new A(int.Parse(t[0]), int.Parse(t[1])));
        }

        int end = int.Parse(sr.ReadLine());

        D.Add(new A(end, 0));
        D.Sort();

        D[0].s = 0;
        Queue<int> Q = new Queue<int>();
        Q.Enqueue(0);

        while (Q.Count > 0)
        {
            int q = Q.Dequeue();
            int l = D[q].d - D[q].s;
            for (int i = q+1;i<D.Count && D[q].d+l>=D[i].d ; i++)
            {
                int m = Math.Max(D[i].d - D[i].len, D[q].d);
                if (D[i].s > m)
                {
                    D[i].s = m;
                    Q.Enqueue(i);
                }
            }
        }


        return D[D.Count-1].s!=int.MaxValue?"YES":"NO";
    }
}
