; using SCM Scheme @ http://people.csail.mit.edu/jaffer/SCM.html
; having issue with formatting output
; this program computes the anwer and pipe its output to the C program for formatting
; use the following command on Unix/Linux System:
;   scm -f <input.scm> < input.in | qrp2format > output.out
; ex: scm -f qrp2.scm < B-small-attempt1.in | qrp2format > B-small-attempt1.out
(define revert
  (lambda (L)
    (letrec
	((revert-helper
	  (lambda (LInput LOutput)
	    (if (null? LInput)
		LOutput
		(revert-helper (cdr LInput) (cons (car LInput) LOutput))))))
      (revert-helper L '()))))

(define range
  (lambda (start count)
    (letrec 
	((range-helper 
	  (lambda (start count L)
	    (if (> count 0)
		(range-helper (+ start 1) (- count 1) (cons start L))
		L))))
      (revert (range-helper start count '())))))

(define pairs
  (lambda (L)
    (letrec
	((pairs-helper
	  (lambda (LOuter Outer LInner LResult)
	    (if (null? LInner)
		(if (null? LOuter)
		    LResult
		    (pairs-helper (cdr LOuter) (car LOuter) (cdr LOuter) LResult))
		(pairs-helper LOuter Outer (cdr LInner) (cons (cons Outer (car LInner)) LResult))))))
      (revert (pairs-helper L 0 '() '())))))

(define aggregate
  (lambda (list accumulator)
    (letrec
	((aggregate-helper
	  (lambda (list value)
	    (if (null? list)
		value
		(aggregate-helper (cdr list) (accumulator value (car list)))))))
      (aggregate-helper (cdr list) (car list)))))

(let ((C (read)))
  (print C)
  (map
   (lambda (i)
     (letrec ((N (read))
	      (ti (map
		   (lambda (j) (read))
		   (range 0 N)))
	      (diff (map
		     (lambda (p) (abs (- (car p) (cdr p))))
		     (pairs ti)))
	      (T 
	       (aggregate diff gcd))
	      (y
	       (modulo (- T (modulo (car ti) T)) T)))
       (print y)))
   (range 1 C)))
