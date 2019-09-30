using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJam
{
    public abstract class GoogleCodeJamApplication
    {
        private List<string> m_InputLines = new List<string>();
        protected List<string> InputLines
        {
            get { return m_InputLines; }
        }

        private int m_nCurrentInputLine = 0;

        List<int> m_CommandValues = new List<int>();
        protected List<int> CommandValues
        {
            get { return m_CommandValues; }
        }

        private int m_nCurrentCommandValue = 0;

        public GoogleCodeJamApplication()
        {
        }

        public void OpenInput(string strInputFileName)
        {
            StreamReader Reader = new StreamReader(strInputFileName);

            string strFileText = Reader.ReadToEnd();
            string[] astrLines = strFileText.Split("\n".ToCharArray());

            foreach (string strLine in astrLines)
            {
                m_InputLines.Add(strLine.TrimEnd("\r".ToCharArray()));
            }

            m_CommandValues = GetNextInputLineAsNumberArray();
        }

        protected string GetNextInputLine()
        {
            return m_InputLines[m_nCurrentInputLine++];
        }

        protected List<int> GetNextInputLineAsNumberArray()
        {
            string strLine = GetNextInputLine();

            string[] astrNumbers = strLine.Split(" ".ToCharArray());

            List<int> Numbers = new List<int>();

            foreach (string strNumber in astrNumbers)
            {
                Numbers.Add(System.Convert.ToInt32(strNumber));
            }

            return Numbers;
        }

        protected int GetNextCommandValue()
        {
            return m_CommandValues[m_nCurrentCommandValue++];
        }

        public void Go(string strInputFileName)
        {
            OpenInput(strInputFileName);
            MarshallInputData();
            Process();
        }

        protected void OutputResult(int nCase, string strResult)
        {
            Console.WriteLine("Case #" + nCase + ": " + strResult);
        }

        public abstract void MarshallInputData();
        public abstract void Process();
    }
}
