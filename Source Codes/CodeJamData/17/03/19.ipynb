{
 "cells": [
  {
   "cell_type": "markdown",
   "metadata": {
    "deletable": true,
    "editable": true
   },
   "source": [
    "# Google Code Jam 2017 — Qualification Round — problem C\n",
    "## User: jdemeyer\n",
    "\n",
    "This is a Jupyter notebook to be run with SageMath version 8.0.beta1 on a 64-bit GNU/Linux system. Although the precise version of SageMath probably does not matter that much."
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 3,
   "metadata": {
    "collapsed": false,
    "deletable": true,
    "editable": true
   },
   "outputs": [],
   "source": [
    "%%cython\n",
    "\n",
    "import os, sys, datetime, time, collections\n",
    "from copy import copy\n",
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
    "        if isinstance(ans, (tuple, list)):\n",
    "            return \" \".join(str(x) for x in ans)\n",
    "        else:\n",
    "            return str(ans)\n",
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
    "class Problem(CodejamProblem):\n",
    "    def __init__(self, input):\n",
    "        CodejamProblem.__init__(self, input)\n",
    "        \n",
    "        T = self.readint()\n",
    "        for i in range(T):\n",
    "            self.cases.append(self.readints())\n",
    "\n",
    "    def solvecase(self, case):\n",
    "        N, K = case\n",
    "        gaps = collections.defaultdict(Integer)\n",
    "        gaps[N] = 1\n",
    "        while K:\n",
    "            sig_check()\n",
    "            maxgap = max(gaps)\n",
    "            S = min(gaps[maxgap], K)\n",
    "            if gaps[maxgap] == S:\n",
    "                del gaps[maxgap]\n",
    "            else:\n",
    "                gaps[maxgap] -= S\n",
    "            lo = (maxgap-1) // 2\n",
    "            hi = maxgap // 2\n",
    "            gaps[lo] = gaps[lo] + S\n",
    "            gaps[hi] = gaps[hi] + S\n",
    "            K -= S\n",
    "        return (hi,lo)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 4,
   "metadata": {
    "collapsed": true,
    "deletable": true,
    "editable": true
   },
   "outputs": [],
   "source": [
    "input=\"\"\"\n",
    "5\n",
    "4 2\n",
    "5 2\n",
    "6 2\n",
    "1000 1000\n",
    "1000 1\n",
    "\"\"\"\n",
    "\n",
    "output=\"\"\"\n",
    "Case #1: 1 0\n",
    "Case #2: 1 0\n",
    "Case #3: 1 1\n",
    "Case #4: 0 0\n",
    "Case #5: 500 499\n",
    "\"\"\""
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
   "outputs": [],
   "source": [
    "input = \"\".join(line+\"\\n\" for line in input.splitlines() if line)\n",
    "output = \"\".join(line+\"\\n\" for line in output.splitlines() if line)"
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
   "outputs": [],
   "source": [
    "P = Problem(input)"
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
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "Case #1: (1, 0)\n",
      "Case #2: (1, 0)\n",
      "Case #3: (1, 1)\n",
      "Case #4: (0, 0)\n",
      "Case #5: (500, 499)\n"
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
   "execution_count": null,
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
      "Traceback (most recent call last):\n",
      "  File \"_home_jdemeyer__sage_temp_tamiyo_4192_tmp_w3z2Iu_spyx_0.pyx\", line 79, in _home_jdemeyer__sage_temp_tamiyo_4192_tmp_w3z2Iu_spyx_0.CodejamProblem.autosolve (_home_jdemeyer__sage_temp_tamiyo_4192_tmp_w3z2Iu_spyx_0.c:5225)\n",
      "    problem = cls(input, *args, **kwds)\n",
      "  File \"_home_jdemeyer__sage_temp_tamiyo_4192_tmp_w3z2Iu_spyx_0.pyx\", line 108, in _home_jdemeyer__sage_temp_tamiyo_4192_tmp_w3z2Iu_spyx_0.Problem.__init__ (_home_jdemeyer__sage_temp_tamiyo_4192_tmp_w3z2Iu_spyx_0.c:6178)\n",
      "    T = self.readint()\n",
      "  File \"_home_jdemeyer__sage_temp_tamiyo_4192_tmp_w3z2Iu_spyx_0.pyx\", line 26, in _home_jdemeyer__sage_temp_tamiyo_4192_tmp_w3z2Iu_spyx_0.CodejamProblem.readint (_home_jdemeyer__sage_temp_tamiyo_4192_tmp_w3z2Iu_spyx_0.c:3272)\n",
      "    return Integer(self.readline())\n",
      "  File \"_home_jdemeyer__sage_temp_tamiyo_4192_tmp_w3z2Iu_spyx_0.pyx\", line 23, in _home_jdemeyer__sage_temp_tamiyo_4192_tmp_w3z2Iu_spyx_0.CodejamProblem.readline (_home_jdemeyer__sage_temp_tamiyo_4192_tmp_w3z2Iu_spyx_0.c:3193)\n",
      "    return next(self.inputlines)\n",
      "StopIteration\n",
      "Read input in 0.00s\n",
      "Parsed input in 0.00s, got 100 cases\n",
      "Solved problem in 0.03s\n"
     ]
    }
   ],
   "source": [
    "P.autosolve(\"in/C-large.in\", \"out\")"
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
