; Question 3 
; A scheme program that does mathematicals and sciences or whatever 
; Yulia Maliauka 
; Professor AJ Bieszczad, Kevin Scrivnor

(define scale '(scale))
;(define scale-func (lambda (y x) (* y x)))

(define scale-func (lambda (y x) (* y x)))

(define fscale (eval scale-func (scheme-report-environment 5)))

(define translate '(translate))
(define translate-func (lambda (y x) (* y x)))
(define fscale (eval scale-func (scheme-report-environment 5)))

(define main
	(lambda ()
		(transform (read) (read) (read))
		))

(define transform 
	(lambda (transformation shape factor) 
		(if (equal? transformation scale) 
			(set! shape (map fscale shape factor))
		) 
		(if (equal? transformation translate) 
			(set! shape (map ftranslate shape factor))
		) 
		(display shape) (newline))
	)




