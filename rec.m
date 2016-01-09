%Matlab Code to generate Switching functions
%Inputs are magnitude u1(:),angle u2(:)
%and ramp time signal for comparison u3(:)
function [sf]=rec(u)
    ts=0.0001; vdc= 400 ;
    peak_phase_max=vdc/sqrt(3);
    x=u(2); 
    y=mod(u(3),ts); 
    z=u(1);
    mag=(z/peak_phase_max)*ts;
    
    %Sector I
    if (x>=0) && (x<pi/3)
      ta = mag * sin(pi/3-x);tb = mag * sin(x);
      t0 =(ts-ta-tb);
      t1 = [t0/4 ta/2 tb/2 t0/2 tb/2 ta/2 t0/4];
      t1=cumsum(t1);
      v1=[0 0 1 0 1 0 0];v2=[0 0 0 0 0 0 0];v3=[1 0 0 1 0 0 1];
            v4=[1 1 1 1 1 1 1];v5=[0 1 0 0 0 1 0];v6=[0 0 0 0 0 0 0];
    for j=1:7
     if(y<t1(j))
        break
     end
    end
    sa=v1(j);sb=v2(j);sc=v3(j);sd=v4(j);se=v5(j);sg=v6(j);
    %sf=[sa sb sc];
    end
%Sector II
    if (x>=pi/3) && (x<2*pi/3)
        adv=x-pi/3;
        tb = mag * sin(pi/3-adv);ta= mag * sin(adv);
        t0 =(ts-ta-tb);
        tl=[t0/4 ta/2 tb/2 t0/2 tb/2 ta/2 t0/4];tl=cumsum(tl);
        v1=[1 1 1 1 1 1 1];v2=[1 0 0 1 0 0 1];v3=[0 0 0 0 0 0 0];
      v4=[0 1 0 0 0 1 0];v5=[0 0 0 0 0 0 0];v6=[0 0 1 0 1 0 0];
       
        for j=1:7
            if(y<tl(j))
                break
            end
        end
        sa=v1(j);sb=v2(j);sc=v3(j);sd=v4(j);se=v5(j);sg=v6(j);
        %sf=[sa sb sc];
    end
    %Sector III
    if(x>=2*pi/3) && (x<pi)
        adv=x-2*pi/3;
        ta =mag * sin(pi/3-adv);tb =mag * sin(adv);
        t0 =(ts-ta-tb);
        t1=[t0/4 ta/2 tb/2 t0/2 tb/2 ta/2 t0/4];
        t1=cumsum(t1);
         
         v1=[0 1 0 0 0 1 0];v2=[0 0 0 0 0 0 0];v3=[0 0 1 0 1 0 0];
        v4=[0 0 0 0 0 0 0];v5=[1 0 0 1 0 0 1];v6=[1 1 1 1 1 1 1];
         for j=1:7
             if(y<t1(j))
                 break
             end
         end
         sa=v1(j);sb=v2(j);sc=v3(j);sd=v4(j);se=v5(j);sg=v6(j);
         %sf=[sa sb sc];
    end
    %Sector IV
    if(x>=-pi) && (x<-2*pi/3)
        adv=x+pi;
        tb =mag * sin(pi/3-adv);ta =mag * sin(adv);
        t0 =(ts-ta-tb);
        t1=[t0/4 ta/2 tb/2 t0/2 tb/2 ta/2 t0/4];t1=cumsum(t1);
        
        v1=[0 0 0 0 0 0 0];v2=[0 0 1 0 1 0 0];v3=[1 1 1 1 1 1 1];
         v4=[1 0 0 1 0 0 1];v5=[0 0 0 0 0 0 0];v6=[0 1 0 0 0 1 0];
         for j=1:7
             if(y<t1(j))
                 break
             end
         end
         sa=v1(j);sb=v2(j);sc=v3(j);sd=v4(j);se=v5(j);sg=v6(j);
         %sf=[sa sb sc];
    end
    %sector V
        if(x>=-2*pi/3)&&(x<-pi/3)
        adv=x+2*pi/3;
        ta=mag*sin(pi/3-adv);
        tb=mag*sin(adv);
        t0=(ts-ta-tb);
        t1=[t0/4 ta/2 tb/2 t0/2 tb/2 ta/2 t0/4];
        t1=cumsum(t1);
        v1=[1 0 0 1 0 0 1];v2=[1 1 1 1 1 1 1];v3=[0 1 0 0 0 1 0];
         v4=[0 0 0 0 0 0 0];v5=[0 0 1 0 1 0 0];v6=[0 0 0 0 0 0 0];
         
       
        for j=1:7
            if(y<t1(j))
                break
            end
        end
        sa=v1(j);sb=v2(j);sc=v3(j);sd=v4(j);se=v5(j);sg=v6(j);
        %sf=[sa sb sc];
        end
        %sector VI
        if (x>=-pi/3) && (x<0)
            adv = x+pi/3;
            tb = mag * sin(pi/3-adv);ta = mag * sin(adv);
            t0 =(ts-ta-tb);
            t1=[t0/4 ta/2 tb/2 t0/2 tb/2 ta/2 t0/4];
            t1=cumsum(t1);
             
            v1=[0 0 0 0 0 0 0];v2=[0 1 0 0 0 1 0];v3=[0 0 0 0 0 0 0];
        v4=[0 0 1 0 1 0 0];v5=[1 1 1 1 1 1 1];v6=[1 0 0 1 0 0 1];
            for j=1:7
                if(y<t1(j))
                    break
                end
            end
            sa=v1(j);sb=v2(j);sc=v3(j);sd=v4(j);se=v5(j);sg=v6(j);
            %sf=[sa sb sc];
            
        end
       sf=[sa sb sc sd se sg];