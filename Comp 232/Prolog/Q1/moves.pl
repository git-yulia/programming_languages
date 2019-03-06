start(st0).

final(st0).

move(st0, 0, st2).
move(st0, 1, st1).

move(st1, 0, st3).
move(st1, 1, st0).

move(st2, 0, st0).
move(st2, 1, st3).

move(st3, 0, st2).
move(st3, 1, st1).


% COMPILE INSTRUCTIONS 
% [dfa].
% [moves_pl].
% parse([0,1,0,0,1]).


