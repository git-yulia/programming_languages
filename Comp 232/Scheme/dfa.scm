; Question 2 
; A scheme program that does stuff
; Yulia Maliauka 
; Professor AJ Bieszczad, Kevin Scrivnor 

; FILE INPUT/OUTPUT 
; Open ports for the input and output files
(define in-file (open-input-file "null.txt"))      ; The file is selected when called for in the test program. 
(define out-file (open-output-file "output.txt"))


(define simulate
  (lambda (dfa input)
    (cons (current-state dfa)               ; start state
          (if (null? input)
              (if (infinal? dfa) '(accept) '(reject))
            (simulate (move dfa (car input)) (cdr input))))))

;; access functions for machine description:
(define current-state car)
(define transition-function cadr)
(define final-states caddr)
(define infinal?
  (lambda (dfa)
    (memq (current-state dfa) (final-states dfa))))
(define continue "Y")

(define move
  (lambda (dfa symbol)
    (let ((cs (current-state dfa)) (trans (transition-function dfa)))
      (list
       (if (eq? cs 'error)
           'error
         (let ((pair (assoc (list cs symbol) trans)))
           (if pair (cadr pair) 'error)))   ; new start state
       trans                                ; same transition function
       (final-states dfa)))))               ; same final states

(define zero-one-even-dfa
 '(q0                                                 ; start state
   (((q0 0) q2) ((q0 1) q1) ((q1 0) q3) ((q1 1) q0)   ; transition fn
    ((q2 0) q0) ((q2 1) q3) ((q3 0) q1) ((q3 1) q2))
   (q0)))                                             ; final states

; TESTS

(define test1
  (lambda ()
    (simulate
     zero-one-even-dfa  ; machine description
     '(0 1 1 0 1))))    ; input string

(define test2
  (lambda ()
    (simulate
     zero-one-even-dfa  ; machine description
     '(0 1 0 0 1 0))))  ; input string

(define main
  (lambda ()
    (begin 
      (display (test3)) (newline) 
      (display "Would you like to go again? [y/n]") (newline)
      (if (equal? "y" (read))
         (main))
      (newline))
    ))

(define test3 
  (lambda ()
    (simulate
      (begin (display "Enter the filename to pull the DFA from: ") (newline) (read (open-input-file(read))))
      (begin (display "Enter a string to check: ") (newline) (read))))
  )


; END INPUT OUTPUT 
; Close the ports
(close-input-port in-file)
(close-output-port out-file)

























