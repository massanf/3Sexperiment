% Fundamental sample codes for DCM-exercise on the 18th of July for your
% reference, supplied and corrected by KOSEKI 2020/06/18
clear all

%Kadai-4.2: I-current controller
% Motor parameters supplied by Prof. Ohnishi
  La=4.63e-3; % [H] Armature inductance
  Ra=0.608; % [ohm] Armature inductance
  Phi=1.0; % [Wb] Magnetic field flux
  Kt=3.69e-2; % Motor constant
  J=1.81e-3; % [Nm^2] Inertia moment of rotary component--- X 100 of the original motor rotor
 
tau_a=La/Ra %Armature time constsnat [s]

% I-current controller gain
KIi=0.5*Ra^2/La % I-current gain based on Kessler's canonical form
tau_ei=2.0*La/Ra % equivalent time constant of the current controller

%Resultna transfer function

% Transfer function from Ia* to Ia
     num1=[1.0]; den1=[tau_ei^2/2.0, tau_ei, 1.0]; 
  sys1=tf(num1, den1)
 
% Transfer function from Vd to Ia
     num2=[2.0*La/Ra/Ra, 0]; den2=[tau_ei^2/2.0, tau_ei, 1.0]; 
  sys2=tf(num2, den2)

% Check fundamental characteristics

figure(1) % frequency characteristics of the current controller
 bode(sys1) ; grid on

figure(2) % pole location
 pzmap(sys1); axis('equal'); sgrid

figure(3) % step response
 step(sys1); grid on;title ('Current command response with correct La')


% Check the voltage disturbance response
figure(4) % step disturbance response
   step(sys2); grid on; title ('Current response to voltage disturbance with correct La')
