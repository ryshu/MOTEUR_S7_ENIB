//************************************************************************
//   IPS - CALCUL D'UN PI 
//   kerhoas@enib.fr
//***********************************************************************

i=0; // index Figures
//-----------------------------------------------------------------------
//    DÃ©finition du Gain et de la Constante de Temps en Boucle Ouverte
//    du systÃ¨me Ã  asservir G/(1+to*s)
//-----------------------------------------------------------------------

G=1150/1000
to=0.0283333

//-----------------------------------------------------------------------
//              Fonction de Transfert en Boucle Ouverte + TracÃ©
//-----------------------------------------------------------------------

s = poly(0, 's');
FTBO = syslin('c', G/(1+to*s));     


//i=i+1;
//figure(i)
//t=0:0.0001:1
//plot2d(t,csim('step',t,FTBO))       
//xgrid
//
//title('FTBO - REPONSE A UN ECHELON')
//
//i=i+1;
//figure(i)
//subplot(1,2,1)
//nyquist(FTBO)
//xgrid                               
//title('FTBO - NYQUIST')
//subplot(1,2,2)
//bode(FTBO)
//xgrid                               
//title('FTBO - BODE')

//-----------------------------------------------------------------------
//              DÃ©finition du Correcteur PI + TracÃ©
//-----------------------------------------------------------------------

ti = 0.1*to // FigÃ©
Kpi = 0.3     // ParamÃ¨tre Ã  rÃ©gler

s = poly(0, 's');
CORR = syslin('c', (Kpi*(ti*s+1))/(ti*s));  

i=i+1;
figure(i)
bode(CORR)
xgrid                   
title('CORRECTEUR PI - BODE')

//-----------------------------------------------------------------------
//     Fonction de Transfert EN BO du SystÃ¨me CorrigÃ© + TracÃ©
//-----------------------------------------------------------------------

FTBO_CORR=CORR*FTBO

i=i+1;
figure(i)
bode(FTBO_CORR)

xgrid
title('FTBO CORRIGE - BODE - MARGE DE PHASE')

//-----------------------------------------------------------------------
//     Fonction de Transfert EN BF du SystÃ¨me CorrigÃ© + TracÃ©
//-----------------------------------------------------------------------

FTBF= (CORR*FTBO)/(1+CORR*FTBO)

i=i+1;
figure(i)
bode(FTBF)
title('FTBF CORRIGE - BODE')
xgrid                                
i=i+1;
figure(i)
t=0:0.0001:1
plot2d(t,csim('step',t,FTBF))         
xgrid                                  
title('FTBF CORRIGE - REPONSE TEMPORELLE A UN ECHELON')

