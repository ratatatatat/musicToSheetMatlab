clear all

[audio,fs] = wavread('AE.wav');
audio = audio(:,1);

i = 1;
while audio(i) < 0.1
    i = i+1;

end

sound(audio, fs)
croppedAudio = audio(i:length(audio));
amps = abs(fft(croppedAudio(2000:50000)));
fqs = 1/length(amps):fs/length(amps):fs;

%sound(croppedAudio,fs)
dynamicFFTplot(croppedAudio, fs, 10000, 2000)

%A = singleWavToNote(croppedAudio(2000:50000),fs)
%plot(fqs(1:700),amps(1:700))


% audioStart = i + 40000
% audioLength = 5000
% croppedAudio = audio(audioStart:audioStart+audioLength);
% 
% fq = 0:fs/audioLength:fs
% 
% t=[1/fs:1/fs:length(croppedAudio)/fs];
% audioFq = (abs(fft(croppedAudio)));
% 
% maxValue = 0;
% maxFq = 0;
% for i = 1:length(audioFq/2)
%     if audioFq(i) > maxValue
%         maxValue = audioFq(i);
%         maxFq = fq(i);
%     end
% end
% maxFq
% 
% sound(croppedAudio,fs)
% plot(fq(1:500),audioFq(1:500))

%plot(t,croppedAudio)
% 
% fs = 44100;
% 
% t = [1/fs:1/fs:1];
% 
% aud = sin(2*pi*440*t);
% plot(t(1:50),aud(1:50))
% sound(aud,fs)
% 
% fqA = real(fft(aud));
% 
% plot(fqA(1:500))