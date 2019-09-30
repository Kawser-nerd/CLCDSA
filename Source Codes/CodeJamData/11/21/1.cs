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

    static void Main(string[] args)
    {
        Reader sr = new Reader("F:\\test\\in.in");
        StreamWriter sw = new StreamWriter("F:\\test\\out.out");
        sw.AutoFlush = true;
        int n = int.Parse(sr.ReadLine());
        Console.WriteLine(n);
        for (int i = 0; i < n; i++)
        {
            sw.WriteLine("Case #" + (i + 1).ToString() + ":");
            string[] t = Solution(sr);
            for (int k = 0; k < t.Length; k++)
            {
                sw.WriteLine(t[k]);
            }
            Console.WriteLine(i);
        }
        sw.Close();
        sr.Close();
        Console.WriteLine("Finished");
        Console.ReadLine();
    }


    static string[] Solution(Reader sr)
    {
        int s = int.Parse(sr.ReadLine());
        string[] g = new string[s];

        int[] W = new int[s];
        int[] L = new int[s];
        double[] OWP = new double[s];

        for (int i = 0; i < s; i++)
        {
            g[i] = sr.ReadLine();
            foreach (var item in g[i])
            {
                if (item == '0')
                    L[i]++;
                if (item == '1')
                    W[i]++;
            }
        }
        for (int i = 0; i < s; i++)
        {
            int gg = 0;
            for (int j = 0; j < s; j++)
            {
                char c = g[i][j];
                if (c != '.')
                {
                    int w = W[j];
                    int l = L[j];
                    if (c == '0')
                        w--;
                    if (c == '1')
                        l--;
                    if (l == 0)
                        OWP[i] += 1;
                    else
                        OWP[i] += (double)w / (double)(w+l);
                    gg++;
                }
            }
            if (gg != 0)
                OWP[i] /= (double)gg;
        }

        string[] ret = new string[s];
        for (int i = 0; i < s; i++)
        {
            double v=0;
            if(L[i]==0)
                v+=0.25;
            else
               v+= 0.25*(double)W[i] / (double)(W[i]+L[i]);
            v+=0.5*OWP[i];
                double k = 0;
                double f = 0; 
            for (int j = 0; j < s; j++)
			{
                if (g[i][j] != '.')
                {
                    k += 0.25 * OWP[j];
                    f++;
                }
			}
            if (f != 0)
                v += k / f;
            ret[i] = string.Format("{0:0.0000000000}", v);
        }
        return ret;

    }
}
