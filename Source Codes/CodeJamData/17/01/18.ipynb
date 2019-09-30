{
 "cells": [
  {
   "cell_type": "markdown",
   "metadata": {
    "deletable": true,
    "editable": true
   },
   "source": [
    "# Google Code Jam 2017 — Qualification Round — problem A\n",
    "## User: jdemeyer\n",
    "\n",
    "This is a Jupyter notebook to be run with SageMath version 8.0.beta1 on a 64-bit GNU/Linux system. Although the precise version of SageMath probably does not matter that much."
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 1,
   "metadata": {
    "collapsed": false,
    "deletable": true,
    "editable": true
   },
   "outputs": [],
   "source": [
    "%%cython\n",
    "\n",
    "import os, sys, datetime, time\n",
    "from sage.rings.integer cimport Integer\n",
    "\n",
    "\n",
    "def log(msg):\n",
    "    sys.stderr.write(msg + \"\\n\")\n",
    "    sys.stderr.flush()\n",
    "\n",
    "\n",
    "class CodejamProblem(object):\n",
    "    def __init__(self, input):\n",
    "        self.inputlines = iter(input.splitlines())\n",
    "        self.cases = []\n",
    "    \n",
    "    def readline(self):\n",
    "        return next(self.inputlines)\n",
    "        \n",
    "    def readint(self):\n",
    "        return Integer(self.readline())\n",
    "\n",
    "    def readints(self):\n",
    "        return [Integer(x) for x in self.readline().split()]\n",
    "        \n",
    "    def solve(self, f=sys.stdout, raw=False):\n",
    "        for i, case in enumerate(self.cases, 1):\n",
    "            sig_check()\n",
    "            ans = self.solvecase(case)\n",
    "            if raw:\n",
    "                ans = repr(ans)\n",
    "            else:\n",
    "                ans = self.formatanswer(ans)\n",
    "            f.write(\"Case #{0}: {1}\\n\".format(i, ans))\n",
    "        f.flush()\n",
    "        \n",
    "    def solvecheck(self, output):\n",
    "        from StringIO import StringIO\n",
    "        out = StringIO()\n",
    "        self.solve(out)\n",
    "        assert out.getvalue() == output\n",
    "            \n",
    "    def formatanswer(self, ans):\n",
    "        return str(ans)\n",
    "\n",
    "    @classmethod\n",
    "    def precompute(cls):\n",
    "        pass\n",
    "    \n",
    "    @classmethod\n",
    "    def autosolve(cls, filein, fileout, *args, **kwds):\n",
    "        log(\"precomputing...\")\n",
    "        cls.precompute()\n",
    "\n",
    "        log(\"autosolving...\")\n",
    "\n",
    "        nexc = 0\n",
    "        while nexc < 10:\n",
    "            sig_check()\n",
    "            t0 = datetime.datetime.now()\n",
    "            try:\n",
    "                input = open(filein).read()\n",
    "            except IOError:\n",
    "                time.sleep(0.2)\n",
    "                continue\n",
    "            d = datetime.datetime.now() - t0\n",
    "            log(\"Read input in %.2fs\" % d.total_seconds())\n",
    "            \n",
    "            t0 = datetime.datetime.now()\n",
    "            try:\n",
    "                problem = cls(input, *args, **kwds)\n",
    "            except Exception:\n",
    "                from traceback import print_exc\n",
    "                print_exc(file=sys.stderr)\n",
    "                nexc += 1\n",
    "                time.sleep(0.5)\n",
    "                continue\n",
    "            d = datetime.datetime.now() - t0\n",
    "            ncases = len(problem.cases)\n",
    "            log(\"Parsed input in %.2fs, got %s cases\" % (d.total_seconds(), ncases))\n",
    "            \n",
    "            t0 = datetime.datetime.now()\n",
    "            with open(fileout, 'w') as out:\n",
    "                problem.solve(out)\n",
    "            d = datetime.datetime.now() - t0\n",
    "            log(\"Solved problem in %.2fs\" % d.total_seconds())\n",
    "\n",
    "            problem.notify()\n",
    "            return\n",
    "        \n",
    "    @staticmethod\n",
    "    def notify():\n",
    "        os.system(\"mplayer /usr/share/apps/kgoldrunner/themes/default/victory.ogg >/dev/null\")\n",
    "\n",
    "\n",
    "from sage.all import PolynomialRing, FiniteField\n",
    "R = PolynomialRing(FiniteField(2), 'x')\n",
    "x = R.gen()\n",
    "\n",
    "def pancakes_to_poly(pancakes):\n",
    "    poly = R()\n",
    "    for d, c in enumerate(pancakes):\n",
    "        if c == \"-\":\n",
    "            poly += x**d\n",
    "    return poly\n",
    "        \n",
    "\n",
    "class Problem(CodejamProblem):\n",
    "    def __init__(self, input):\n",
    "        CodejamProblem.__init__(self, input)\n",
    "        \n",
    "        T = self.readint()\n",
    "        for i in range(T):\n",
    "            pancakes, K = self.readline().split()\n",
    "            self.cases.append((pancakes, Integer(K)))\n",
    "\n",
    "    def solvecase(self, case):\n",
    "        target = pancakes_to_poly(case[0])\n",
    "        flipper = pancakes_to_poly(\"-\" * case[1])\n",
    "        q, r = target.quo_rem(flipper)\n",
    "        if r:\n",
    "            return \"IMPOSSIBLE\"\n",
    "        return q.hamming_weight()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 2,
   "metadata": {
    "collapsed": true,
    "deletable": true,
    "editable": true
   },
   "outputs": [],
   "source": [
    "input=\"\"\"\n",
    "3\n",
    "---+-++- 3\n",
    "+++++ 4\n",
    "-+-+- 4\n",
    "\"\"\"\n",
    "\n",
    "output=\"\"\"\n",
    "Case #1: 3\n",
    "Case #2: 0\n",
    "Case #3: IMPOSSIBLE\n",
    "\"\"\""
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 3,
   "metadata": {
    "collapsed": true,
    "deletable": true,
    "editable": true
   },
   "outputs": [],
   "source": [
    "input = \"\".join(line+\"\\n\" for line in input.splitlines() if line)\n",
    "output = \"\".join(line+\"\\n\" for line in output.splitlines() if line)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 4,
   "metadata": {
    "collapsed": false,
    "deletable": true,
    "editable": true
   },
   "outputs": [],
   "source": [
    "P = Problem(input)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 5,
   "metadata": {
    "collapsed": false,
    "deletable": true,
    "editable": true
   },
   "outputs": [
    {
     "data": {
      "text/plain": [
       "x^7 + x^4 + x^2 + x + 1"
      ]
     },
     "execution_count": 5,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "pancakes_to_poly(P.cases[0][0])"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 6,
   "metadata": {
    "collapsed": false,
    "deletable": true,
    "editable": true
   },
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "Case #1: 3\n",
      "Case #2: 0\n",
      "Case #3: 'IMPOSSIBLE'\n"
     ]
    }
   ],
   "source": [
    "P.solve(raw=True)\n",
    "P.solvecheck(output)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 7,
   "metadata": {
    "collapsed": false,
    "deletable": true,
    "editable": true
   },
   "outputs": [
    {
     "name": "stderr",
     "output_type": "stream",
     "text": [
      "precomputing...\n",
      "autosolving...\n",
      "Read input in 0.00s\n",
      "Parsed input in 0.00s, got 100 cases\n",
      "Solved problem in 0.00s\n"
     ]
    }
   ],
   "source": [
    "P.autosolve(\"in/A-small-attempt0.in\", \"out/A\")"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "metadata": {
    "collapsed": true,
    "deletable": true,
    "editable": true
   },
   "outputs": [],
   "source": []
  }
 ],
 "metadata": {
  "kernelspec": {
   "display_name": "SageMath 8.0.beta1",
   "language": "",
   "name": "sagemath"
  },
  "language_info": {
   "codemirror_mode": {
    "name": "ipython",
    "version": 2
   },
   "file_extension": ".py",
   "mimetype": "text/x-python",
   "name": "python",
   "nbconvert_exporter": "python",
   "pygments_lexer": "ipython2",
   "version": "2.7.13"
  }
 },
 "nbformat": 4,
 "nbformat_minor": 0
}
