% Yulia Maliauka
% Question 3, Prolog Lab (13)
% Professor Bieszczad, Prof. Scrivnor

:- dynamic(flight/6).
:- dynamic(airline/2).
:- dynamic(airport/3).

% functions
% format: flight('ID',NUM,'START','END',HRS,COST).

% Query if a flight is domestic
domestic(Trip) :-
  Trip(),
  write(Country), nl.
