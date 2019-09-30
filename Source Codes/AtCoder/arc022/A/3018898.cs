using System;
using System.Collections.Generic;

namespace compiler
{
	class Inst
	{
		public string opcode;//???
		public char c;//???Char??????????
		public int x;//???1?Jump,Split??????
		public int y;//???2?Split??????????
	}
	class Executer
	{
		public static List<Inst> commandlist = new List<Inst>();
		public static string text;
		public static int Recursive(int pc, int sp)
		{
			switch (commandlist[pc].opcode)
			{
				case "Char":
					if (sp >= text.Length)
						return 0;//???????????????
					if (commandlist[pc].c != text[sp] && commandlist[pc].c != '.')//?????????????
						return 0;
					return Recursive(pc + 1, sp + 1);//???????
				case "Match":
					return sp >= text.Length ? 1 : 0;//?????????????????
				case "Jump":
					return Recursive(commandlist[pc].x, sp);//x??????
				case "Split":
					if (Recursive(commandlist[pc].x, sp) == 1)//x??????
						return 1;
					return Recursive(commandlist[pc].y, sp);//y??????
			}
			return -1;//???
		}
	}
	class Convert //??class?????????????????????
	{
		static int Make_Char(string s)//Char???????
		{
			int ret = Executer.commandlist.Count;
			Inst inst = new Inst() { opcode = "Char", c = s[0], };
			Executer.commandlist.Add(inst);
			return ret;
		}
		static int Make_Jump()//Jump???????
		{
			int ret = Executer.commandlist.Count;
			Inst inst = new Inst() { opcode = "Jump", };
			Executer.commandlist.Add(inst);
			return ret;
		}
		static int Make_Split()//Split???????
		{
			int ret = Executer.commandlist.Count;
			Inst inst = new Inst() { opcode = "Split", };
			Executer.commandlist.Add(inst);
			return ret;
		}
		static int Expression(string s)//????????????
		{
			int ret = Executer.commandlist.Count;
			if (string.IsNullOrEmpty(s)) return ret - 1;
			switch (s[s.Length - 1])
			{
				case ('?'):
				{
					int sprit = Make_Split();
					Executer.commandlist[sprit].x = Expression(s.Substring(0, s.Length - 1));
					Executer.commandlist[sprit].y = Executer.commandlist.Count;
					break;
				}
				case ('*'):
				{
					int sprit = Make_Split();
					Executer.commandlist[sprit].x = Expression(s.Substring(0, s.Length - 1));
					int jump = Make_Jump();
					Executer.commandlist[jump].x = sprit;
					Executer.commandlist[sprit].y = Executer.commandlist.Count;
					break;
				}
				case ('+'):
				{
					int start = Expression(s.Substring(0, s.Length - 1));
					int sprit = Make_Split();
					Executer.commandlist[sprit].x = start; Executer.commandlist[sprit].y = Executer.commandlist.Count;
					break;
				}
				case (')')://??????????()???????????)??????????????s???()
				{
					Sentence(s.Substring(1, s.Length - 2));
					break;
				}
				default:
				{
					Make_Char(s);
					break;
				}
			}
			return ret;
		}
		static int Term(string s)//????????
		{
			int ret = Executer.commandlist.Count;
			int start_string = 0;
			for (int i = 0; i < s.Length; i++)
			{
				if (s[i] == '(')
				{
					Expression(s.Substring(start_string, i - start_string));
					start_string = i;
					int count = 0;
					do//()???????????
					{
						switch (s[i])
						{
							case ('('): { count++; break; }
							case (')'): { count--; break; }
							default: break;
						}
						i++;
					} while (count > 0);
					if (i >= s.Length)//??????????????
						break;
				}
				// )a????????????else if?????
				if (s[i] == '.' || char.IsLetter(s[i]))//??????????????????????????
				{
					Expression(s.Substring(start_string, i - start_string));
					start_string = i;
				}
			}
			Expression(s.Substring(start_string, s.Length - start_string));
			return ret;
		}
		static int Sentence(string s)//????????
		{
			bool found = false;
			int bracketscount = 0;//()????????????????
			for (int i = 0; i < s.Length && !found; i++)
			{
				if (s[i] == '(') bracketscount++;
				else if (s[i] == ')') bracketscount--;
				else if (s[i] == '|' && bracketscount == 0)
				{
					found = true;
					int sprit = Make_Split();
					Executer.commandlist[sprit].x = Term(s.Substring(0, i));//??????????????????????????
					int jump = Executer.commandlist.Count; Make_Jump();
					Executer.commandlist[sprit].y = Sentence(s.Substring(i + 1, s.Length - (i + 1)));
					Executer.commandlist[jump].x = Executer.commandlist.Count;
					return sprit;
				}
			}
			return Term(s);
		}
		public static void Input_regexp(string s)//?????????????
		{
			if (s[0] == '^') s = s.Substring(1, s.Length - 1);
			if (s[s.Length - 1] == '$') s = s.Substring(0, s.Length - 1);
			Sentence(s);
			Inst finish = new Inst() { opcode = "Match", };
			Executer.commandlist.Add(finish);
		}
	}
	class Program
	{
		static void Main(string[] args)
		{
			Convert.Input_regexp("^.*I.*C.*T.*$");
			Executer.text = Console.ReadLine().ToUpper();
			Console.WriteLine(Executer.Recursive(0, 0) == 1 ? "YES" : "NO");
		}
	}
}