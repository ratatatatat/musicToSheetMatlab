function [ note ] = singleWavToNote ( wav, fs )

letters = ['C ';'Cs';'D ';'Ds';'E ';'F ';'Fs';'G ';'Gs';'A ';'As';'B '];
mfqNums = 3;
MFQ = maxFreq( wav, fs, mfqNums)

fqDiff = zeros(mfqNums-1,1);

for i = 1:mfqNums-1
   fqDiff(i,1) = MFQ(i+1,1)-MFQ(i,1);
end

fqMean = mean(fqDiff)

fqStrRep = dec2base(round(12*log2(fqMean/16.35)),12)

note = strcat(letters(base2dec(fqStrRep(2),12)+1,1:2),fqStrRep(1));
end