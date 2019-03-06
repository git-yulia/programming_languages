; Question 1
; A scheme program that takes input(function, list)
; Yulia Maliauka
; Professor AJ Bieszczad, Kevin Scrivnor

; Example program: use for tests
; (lambda (x) (+ 3 x))

(define funct (read))

(define f (eval funct (scheme-report-environment 5)))

(define data (read))

(map f data)

;
