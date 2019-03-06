% Yulia Maliauka
% Question 2
% Professor Scrivnor, Professor Bieszczad

% PANDORIFY: The ultimate music streaming software that HASNT been sued by Sony or Taylor Swift (yet).

% MUSIC LIBRARY

% TOOL collection
track('Skizm', 'Third Eyes and Five Wives', 'Tool', 'Trash', 'Apple lossful', 100).
track('Fourth Eye', 'Third Eyes and Five Wives', 'Tool', 'Trash', 'Apple lossful', 150).
track('Rosetta Boned', 'Third Eyes and Five Wives', 'Tool', 'Trash', 'Apple lossful', 200).
track('Hooters banned me in Louisiana', 'Third Eyes and Five Wives', 'Tool', 'Trash', 'Apple lossful', 250).
track('DMT Brunch', 'Third Eyes and Five Wives', 'Tool', 'Trash', 'Apple lossful', 300).
track('Parabolic Yeast Infection', 'Third Eyes and Five Wives', 'Tool', 'Trash', 'Apple lossful', 350).
track('The Grunge', 'Third Eyes and Five Wives', 'Tool', 'Trash', 'Apple lossful', 400).
track('Burning man changed my life', 'Third Eyes and Five Wives', 'Tool', 'Trash', 'Apple lossful', 450).
track('The government is gonna take our third eyes', 'Third Eyes and Five Wives', 'Tool', 'Trash', 'Apple lossful', 500).
track('RIP Bill Hicks', 'Third Eyes and Five Wives', 'Tool', 'Trash', 'Apple lossful', 550).

track('Syke-o on my Trike-o', '10,000 Hoes', 'Tool', 'Indie Pop', 'Jpeg', 550).
track('Who let the dogs out of their existential nightmare', '10,000 Hoes', 'Tool', 'Indie Pop', 'Jpeg', 550).
track('Why are my hands warping', '10,000 Hoes', 'Tool', 'Indie Pop', 'Jpeg', 550).
track('Schism', '10,000 Hoes', 'Tool', 'Indie Pop', 'Jpeg', 550).
track('The Pots and Pans', '10,000 Hoes', 'Tool', 'Indie Pop', 'Jpeg', 550).
track('Vicarious is a Big Word, Jimmy', '10,000 Hoes', 'Tool', 'Indie Pop', 'Jpeg', 550).
track('Untitled 01', '10,000 Hoes', 'Tool', 'Indie Pop', 'Jpeg', 550).
track('Wings for Me (Pt 1)', '10,000 Hoes', 'Tool', 'Indie Pop', 'Jpeg', 550).
track('Wings for Me (Pt 2)', '10,000 Hoes', 'Tool', 'Indie Pop', 'Jpeg', 550).
track('So long and thanks for all the hoes', '10,000 Hoes', 'Tool', 'Indie Pop', 'Jpeg', 550).
% end of TOOL collection (20 songs)

% Ska collection
track('Is that a trombone in your pants, et. al','Cheer Up','Reel Big Fish','Ska','Mpeg-4', 333).
track('Donald Trumpet Theme 03','Cheer Up','Reel Big Fish','Ska','Mpeg-4',333).
track('God is a trombonist','Cheer Up','Reel Big Fish','Ska','Mpeg-4',333).
track('Untitled 01','Communism?','Streetlight Manifesto','Ska','Mpeg-4',333).
track('Marx','Communism?','Streetlight Manifesto','Ska','Mpeg-4',333).
track('Russia','Communism?','Streetlight Manifesto','Ska','Mpeg-4',333).
track('Cold War Blues','Communism?','Streetlight Manifesto','Ska','Mpeg-4',333).
track('IT is a Science, Too','I fixed a projector once','Connor Ska-sborn','Ska','Mpeg-4',333).
track('Crushed IT','I fixed a projector once','Connor Ska-sborn','Ska','Mpeg-4',333).
track('Yulia Sucks','I fixed a projector once','Connor Ska-sborn','Ska','Mpeg-4',333).
% end of Ska collection (10 songs)

% Papa Roach collection
track('Cut My Life Into Pieces', 'Death Motorcycle', 'Papa Roach', 'Trash', 'Apple lossless', 790).
track('Sadness makes me happy', 'Death Motorcycle', 'Papa Roach', 'Trash', 'Apple lossless', 790).
track('My mother didnt accept me as a teen', 'Death Motorcycle', 'Papa Roach', 'Trash', 'Apple lossless', 790).
track('I have latent homosexual feelings', 'Death Motorcycle', 'Papa Roach', 'Trash', 'Apple lossless', 790).
track('Cut My Mom Into Pieces', 'Death Motorcycle', 'Papa Roach', 'Trash', 'Apple lossless', 790).
track('I do Prolog to alleviate depression', 'Death Motorcycle', 'Papa Roach', 'Trash', 'Apple lossless', 790).
track('Prolog is like Prozac, but cheaper', 'Death Motorcycle', 'Papa Roach', 'Trash', 'Apple lossless', 790).
track('Cut My homework Into Pieces', 'Death Motorcycle', 'Papa Roach', 'Trash', 'Apple lossless', 790).
track('Untitled 01', 'Death Motorcycle', 'Papa Roach', 'Trash', 'Apple lossless', 790).
track('The folly of mankind', 'Death Motorcycle', 'Papa Roach', 'Trash', 'Apple lossless', 790).
% end of Papa Roach collection (10 songs)



% KScrivs Mixtape
track('Prolog Prologue','M.S. in Mixing','KScrivs','Bit Hop','FLAC', 1411).
track('L33t Beats','M.S. in Mixing','KScrivs','Bit Hop','FLAC', 1411).
track('I teach the lab section of 232','M.S. in Mixing','KScrivs','Bit Hop','FLAC', 1411).
track('Teachin those kids a lesson','M.S. in Mixing','KScrivs','Bit Hop','FLAC', 1411).
track('Tangarang','M.S. in Mixing','KScrivs','Bit Hop','FLAC', 1411).
track('9GAG 4 LIF3','M.S. in Mixing','KScrivs','Bit Hop','FLAC', 1411).
track('I punched a dolphin','M.S. in Mixing','KScrivs','Bit Hop','FLAC', 1411).
track('Where ma Tang at?','M.S. in Mixing','KScrivs','Bit Hop','FLAC', 1411).
track('Calc 1 and Done','M.S. in Mixing','KScrivs','Bit Hop','FLAC', 1411).
track('Prolog Epilogue Monologue','M.S. in Mixing','KScrivs','Bit Hop','FLAC', 1411).
% end of KScrivs Mixtape (10 songs)


% END OF MUSIC LIBRARY



% FUNCTIONS FOR ACCESSING MUSIC LIBRARY

% This function grabs all the tunes created by a given artist.
tunes(Artist) :-
	track(Tune, Album, Artist, Genre, Format, Bitrate),
	write(Tune), nl, fail.
		% The fail commands forces Prolog to backtrack until there are no options left.
tunes(Artist) :- true.

% This function gives all tunes in a given album
tracklist(Album) :-
	track(Tune, Album, Artist, Genre, Format, Bitrate),
	write(Tune), nl, fail.
		% The fail commands forces Prolog to backtrack until there are no options left.
tracklist(Album) :- true.

% This function reports all artists performing the same tunes
songs(Tune) :-
	track(Tune, Album, Artist, Genre, Format, Bitrate),
	write(Artist), write(' played '), write(Tune), write(' on the '), write(Album), write(' album.'), nl, fail.
		% The fail commands forces Prolog to backtrack until there are no options left.
	songs(Artist) :- true.

% This function displays all the songs with a higher bit rate than given
bitrate(BitrateX) :-
	track(Tune, Album, Artist, Genre, Format, Bitrate),
	( Bitrate > BitrateX -> write(Tune), nl, fail), nl, fail.
bitrate(BitrateX) :- true.

% This function displays all the songs in a given genre
genre(Genre) :-
	track(Tune, Album, Artist, Genre, Format, Bitrate),
	write(Tune), write(' is a good example of a '), write(Genre), write(' track. '), nl, fail.
genre(Genre) :- true.

% This function displays all the artists who make music in a given genre
groupies(Genre) :-
	track(Tune, Album, Artist, Genre, Format, Bitrate),
	write(Artist), write(' is a good example of a '), write(Genre), write(' artist. '), nl, fail.
groupies(Genre) :- true.

% This function displays all available encodings of a given song
encodings(Tune) :-
	track(Tune, Album, Artist, Genre, Format, Bitrate),
	write(Format), nl, fail.
encodings(Tune) :- true.

% This function displays all available bit rates of a given song
bitrates(Tune) :-
	track(Tune, Album, Artist, Genre, Format, Bitrate),
	write(Bitrate), nl, fail.
bitrates(Tune) :- true.





















%
