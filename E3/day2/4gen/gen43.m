% Fundamental sample codes for DCM-exercise on the 18th of July for your
% reference, 2020 by KOSEKI

%Kadai-4.3: Case studies for wrong plant identification

Lab=1.2*La; Las=0.8*La; 

num1b=[KIi]; den1b=[Lab, Ra, KIi]; num2b=[1.0, 0];
sys1b=tf(num1b, den1b)
sys2b=tf(num2b, den1b)
figure(5); step(sys1b); grid on; title ('Current command response with larger La')
figure(6); step(sys2b); grid on; title ('Current response to voltage disturbance with larger La')

num1s=[KIi]; den1s=[Las, Ra, KIi]; num2s=[1.0, 0];
sys1s=tf(num1s, den1s);
 sys2s=tf(num2s, den1s);
figure(7); step(sys1s); grid on; title ('Current command response with smaller La')
figure(8); step(sys2s); grid on; title ('Current response to voltage disturbance with smaller La')
