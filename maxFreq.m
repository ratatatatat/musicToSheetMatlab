function [ Lmax ] = maxFreq( wav, fs, numMax)
%Takes wav file and computes the first numMax
% maxima of the fourier transform

minFreq = 100;

len = size(wav);
len = len(1);
fq = 1/len:fs/len:fs;
Lmax = zeros(numMax,2);

array = abs(fft(wav));
thresh = mean(array(1:100))*5;
nMax = 1;
i = 3;

while fq(i) < minFreq
    i = i+1;
end

while nMax <= numMax
   if array(i) > array(i+1) && array(i) > array(i-1) && array(i) > thresh
   
      Lmax(nMax,1) = fq(i);
      Lmax(nMax,2) = array(i);
      nMax = nMax+1;
   end
   i = i+1;
   
end

end