
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static FILE *fp;

int main ( void )
{
    double degrad;
    double angle;
    double rangle;
    double x,y;
    double ax,ay;
    double bx,by;
    double cx,cy;
    double midlane;
    double lane[15];
    double xlane[4];
    double xangle[360];
    double xax[360];
    double xay[360];

    unsigned int min[10];
    unsigned int max[10];

    unsigned int ra;
    unsigned int rb;
    unsigned int rc;
    unsigned int rd;

    //unsigned int bangle[12];

    degrad = 1.0 / 180.0 * M_PI;


    cx=18.6;
    for(ra=0;ra<15;ra++,cx+=1.0)
    {
        lane[ra]=cx;
    }

    cx=16.0;
    for(ra=0;ra<4;ra++,cx-=1.0)
    {
        xlane[ra]=cx;
    }


    angle = 0.0;
    for(ra=0;ra<120;ra++,angle+=3)
    {
        rangle=angle*degrad;
        x = cos(rangle);
        y = -sin(rangle);
        xangle[ra]=angle;
        xax[ra]=x;
        xay[ra]=y;
    }

    for(ra=0;ra<10;ra++)
    {
        min[ra]=120;
        max[ra]=0;
    }


    fp=fopen("clock60.kicad_pcb","wt");
    if(fp==NULL) return(1);

    fprintf(fp,"(kicad_pcb (version 4) (host pcbnew 4.0.7-e2-6376~58~ubuntu16.04.1)\n");
    fprintf(fp,"\n");
    fprintf(fp,"  (general\n");
    fprintf(fp,"    (links 0)\n");
    fprintf(fp,"    (no_connects 0)\n");
    fprintf(fp,"    (area 150 100 180 100)\n");
    fprintf(fp,"    (thickness 1.6)\n");
    fprintf(fp,"    (drawings 2)\n");
    fprintf(fp,"    (tracks 0)\n");
    fprintf(fp,"    (zones 0)\n");
    fprintf(fp,"    (modules 0)\n");
    fprintf(fp,"    (nets 1)\n");
    fprintf(fp,"  )\n");
    fprintf(fp,"\n");
    fprintf(fp,"  (page A4)\n");
    fprintf(fp,"  (layers\n");
    fprintf(fp,"    (0 F.Cu signal)\n");
    fprintf(fp,"    (31 B.Cu signal)\n");
    fprintf(fp,"    (32 B.Adhes user)\n");
    fprintf(fp,"    (33 F.Adhes user)\n");
    fprintf(fp,"    (34 B.Paste user)\n");
    fprintf(fp,"    (35 F.Paste user)\n");
    fprintf(fp,"    (36 B.SilkS user)\n");
    fprintf(fp,"    (37 F.SilkS user)\n");
    fprintf(fp,"    (38 B.Mask user)\n");
    fprintf(fp,"    (39 F.Mask user)\n");
    fprintf(fp,"    (40 Dwgs.User user)\n");
    fprintf(fp,"    (41 Cmts.User user)\n");
    fprintf(fp,"    (42 Eco1.User user)\n");
    fprintf(fp,"    (43 Eco2.User user)\n");
    fprintf(fp,"    (44 Edge.Cuts user)\n");
    fprintf(fp,"    (45 Margin user)\n");
    fprintf(fp,"    (46 B.CrtYd user)\n");
    fprintf(fp,"    (47 F.CrtYd user)\n");
    fprintf(fp,"    (48 B.Fab user)\n");
    fprintf(fp,"    (49 F.Fab user)\n");
    fprintf(fp,"  )\n");
    fprintf(fp,"\n");
    fprintf(fp,"  (setup\n");
    fprintf(fp,"    (last_trace_width 0.25)\n");
    fprintf(fp,"    (trace_clearance 0.2)\n");
    fprintf(fp,"    (zone_clearance 0.508)\n");
    fprintf(fp,"    (zone_45_only no)\n");
    fprintf(fp,"    (trace_min 0.2)\n");
    fprintf(fp,"    (segment_width 0.2)\n");
    fprintf(fp,"    (edge_width 0.15)\n");
    fprintf(fp,"    (via_size 0.6)\n");
    fprintf(fp,"    (via_drill 0.4)\n");
    fprintf(fp,"    (via_min_size 0.4)\n");
    fprintf(fp,"    (via_min_drill 0.3)\n");
    fprintf(fp,"    (uvia_size 0.3)\n");
    fprintf(fp,"    (uvia_drill 0.1)\n");
    fprintf(fp,"    (uvias_allowed no)\n");
    fprintf(fp,"    (uvia_min_size 0.2)\n");
    fprintf(fp,"    (uvia_min_drill 0.1)\n");
    fprintf(fp,"    (pcb_text_width 0.3)\n");
    fprintf(fp,"    (pcb_text_size 1.5 1.5)\n");
    fprintf(fp,"    (mod_edge_width 0.15)\n");
    fprintf(fp,"    (mod_text_size 1 1)\n");
    fprintf(fp,"    (mod_text_width 0.15)\n");
    fprintf(fp,"    (pad_size 1.524 1.524)\n");
    fprintf(fp,"    (pad_drill 0.762)\n");
    fprintf(fp,"    (pad_to_mask_clearance 0.2)\n");
    fprintf(fp,"    (aux_axis_origin 0 0)\n");
    fprintf(fp,"    (visible_elements FFFFFF7F)\n");
    fprintf(fp,"    (pcbplotparams\n");
    fprintf(fp,"      (layerselection 0x00030_80000001)\n");
    fprintf(fp,"      (usegerberextensions false)\n");
    fprintf(fp,"      (excludeedgelayer true)\n");
    fprintf(fp,"      (linewidth 0.150000)\n");
    fprintf(fp,"      (plotframeref false)\n");
    fprintf(fp,"      (viasonmask false)\n");
    fprintf(fp,"      (mode 1)\n");
    fprintf(fp,"      (useauxorigin false)\n");
    fprintf(fp,"      (hpglpennumber 1)\n");
    fprintf(fp,"      (hpglpenspeed 20)\n");
    fprintf(fp,"      (hpglpendiameter 15)\n");
    fprintf(fp,"      (hpglpenoverlay 2)\n");
    fprintf(fp,"      (psnegative false)\n");
    fprintf(fp,"      (psa4output false)\n");
    fprintf(fp,"      (plotreference true)\n");
    fprintf(fp,"      (plotvalue true)\n");
    fprintf(fp,"      (plotinvisibletext false)\n");
    fprintf(fp,"      (padsonsilk false)\n");
    fprintf(fp,"      (subtractmaskfromsilk false)\n");
    fprintf(fp,"      (outputformat 1)\n");
    fprintf(fp,"      (mirror false)\n");
    fprintf(fp,"      (drillshape 1)\n");
    fprintf(fp,"      (scaleselection 1)\n");
    fprintf(fp,"      (outputdirectory \"\"))\n");
    fprintf(fp,"  )\n");
    fprintf(fp,"\n");
    fprintf(fp,"  (net 0 \"\")\n");
    fprintf(fp,"\n");
    fprintf(fp,"  (net_class Default \"This is the default net class.\"\n");
    fprintf(fp,"    (clearance 0.2)\n");
    fprintf(fp,"    (trace_width 0.25)\n");
    fprintf(fp,"    (via_dia 0.6)\n");
    fprintf(fp,"    (via_drill 0.4)\n");
    fprintf(fp,"    (uvia_dia 0.3)\n");
    fprintf(fp,"    (uvia_drill 0.1)\n");
    fprintf(fp,"  )\n");
    fprintf(fp,"\n");

    //place fab reference lines/numbers
    for(ra=0;ra<120;ra++)
    {
        ax = xax[ra] * 9;
        ay = xay[ra] * 9;
        bx = xax[ra] * 30;
        by = xay[ra] * 30;
        cx = xax[ra] * 32;
        cy = xay[ra] * 32;
        ax +=150.0;
        ay +=100.0;
        bx +=150.0;
        by +=100.0;
        cx +=150.0;
        cy +=100.0;
        fprintf(fp,"  (gr_line (start %10.3lf %10.3lf) (end %10.3lf %10.3lf) (angle %5.1lf) (layer F.Fab) (width 0.05))\n",ax,ay,bx,by,xangle[ra]);
        fprintf(fp,"  (gr_text \" %u %3.1lf\" (at %10.3lf %10.3lf %5.1lf) (layer F.Fab)(effects (font (size 0.5 0.5) (thickness 0.1))) )\n",ra,xangle[ra],cx,cy,xangle[ra]);
    }

    //place leds
    rc=0; rd=1;
    for(ra=0;ra<120;ra+=2)
    {
        fprintf(fp,"  (module min:hand (layer F.Cu) (tedit 57FE93A5) (tstamp 5AA34834) \n");
        fprintf(fp,"    (at 150 100 %5.1lf)\n",xangle[ra]);
        fprintf(fp,"    (fp_text reference %u (at %10.3lf 1 %3.1lf) (layer F.Fab)(effects (font (size 0.5 0.5) (thickness 0.05))))\n",rc,16.0,xangle[ra]);
        fprintf(fp,"    (fp_text value     %u (at %10.3lf 1 %3.1lf) (layer F.Fab)(effects (font (size 0.5 0.5) (thickness 0.05))))\n",rd,17.6,xangle[ra]);
        fprintf(fp,"    (descr \"0603\")\n");
        fprintf(fp,"    (attr smd)\n");
        fprintf(fp,"    (pad 1 smd rect (at %5.1lf 0 %5.1lf) (size 0.8 0.8) (layers F.Cu F.Paste F.Mask))\n",16.0,xangle[ra]);
        fprintf(fp,"    (pad 2 smd rect (at %5.1lf 0 %5.1lf) (size 0.8 0.8) (layers F.Cu F.Paste F.Mask))\n",17.6,xangle[ra]);
        fprintf(fp,"  )\n");

        ax = xax[ra] * 17.6;
        ay = xay[ra] * 17.6;
        bx = xax[ra] * lane[rd];
        by = xay[ra] * lane[rd];
        ax +=150.0;
        ay +=100.0;
        bx +=150.0;
        by +=100.0;
        fprintf(fp,"  (segment (start %10.3lf %10.3lf) (end %10.3lf %10.3lf) (width 0.2) (layer F.Cu) (net 0))\n",ax,ay,bx,by);
        fprintf(fp,"  (via (at %10.3lf %10.3lf) (size 0.6) (drill 0.4) (layers F.Cu B.Cu) (net 0))\n",bx,by);
if(min[rd]>ra) min[rd]=ra;
if(max[rd]<ra) max[rd]=ra;

        if(ra<=14)
        {
            ax = xax[ra] * lane[10];
            ay = xay[ra] * lane[10];
            ax +=150.0;
            ay +=100.0;
            fprintf(fp,"  (segment (start %10.3lf %10.3lf) (end %10.3lf %10.3lf) (width 0.2) (layer F.Cu) (net 0))\n",ax,ay,bx,by);

            fprintf(fp,"  (module resi:stor (layer F.Cu) (tedit 57FE93A5) (tstamp 5AA34834) \n");
            fprintf(fp,"    (at 150 100 %5.1lf)\n",xangle[ra]);
            fprintf(fp,"    (fp_text reference x (at %10.3lf 0 %3.1lf) (layer F.Fab)(effects (font (size 0.5 0.5) (thickness 0.05))))\n",lane[10]+0.0,xangle[ra]);
            fprintf(fp,"    (fp_text value     x (at %10.3lf 0 %3.1lf) (layer F.Fab)(effects (font (size 0.5 0.5) (thickness 0.05))))\n",lane[10]+1.6,xangle[ra]);
            fprintf(fp,"    (descr \"0603\")\n");
            fprintf(fp,"    (attr smd)\n");
            fprintf(fp,"    (pad 1 smd rect (at %5.1lf 0 %5.1lf) (size 0.8 0.8) (layers F.Cu F.Paste F.Mask))\n",lane[10]+0.0,xangle[ra]);
            fprintf(fp,"    (pad 2 smd rect (at %5.1lf 0 %5.1lf) (size 0.8 0.8) (layers F.Cu F.Paste F.Mask))\n",lane[10]+1.6,xangle[ra]);
            fprintf(fp,"  )\n");
            ax = xax[ra] * (lane[10]+1.6);
            ay = xay[ra] * (lane[10]+1.6);
            ax +=150.0;
            ay +=100.0;
            bx = xax[ra] * (lane[10]+3.6);
            by = xay[ra] * (lane[10]+3.6);
            bx +=150.0;
            by +=100.0;
            fprintf(fp,"  (segment (start %10.3lf %10.3lf) (end %10.3lf %10.3lf) (width 0.2) (layer F.Cu) (net 0))\n",ax,ay,bx,by);

            fprintf(fp,"  (module pin:hole (layer F.Cu) (tedit 59650532) (tstamp 5AA6FE27)\n");
            fprintf(fp,"    (at %10.3lf %10.3lf)\n",bx,by);
            fprintf(fp,"    (descr \"pinhole\")\n");
            fprintf(fp,"    (tags \"hole\")\n");
            fprintf(fp,"    (fp_text reference x (at 0 0) (layer F.Fab) (effects (font (size 0.1 0.1) (thickness 0.01))) )\n");
            fprintf(fp,"    (fp_text value     x (at 0 0) (layer F.Fab) (effects (font (size 0.1 0.1) (thickness 0.01))) )\n");
            fprintf(fp,"    (pad %u thru_hole rect (at 0 0 %3.1lf)    (size 1.7 1.7) (drill 1) (layers *.Cu *.Mask))\n",(ra>>1)+1,xangle[ra]);
            fprintf(fp,"  )\n");
        }

        ax = xax[ra+1] * xlane[0];
        ay = xay[ra+1] * xlane[0];
        bx = xax[ra+1] * lane[rc];
        by = xay[ra+1] * lane[rc];
        ax +=150.0;
        ay +=100.0;
        bx +=150.0;
        by +=100.0;
        fprintf(fp,"  (segment (start %10.3lf %10.3lf) (end %10.3lf %10.3lf) (width 0.2) (layer F.Cu) (net 0))\n",ax,ay,bx,by);
        fprintf(fp,"  (via (at %10.3lf %10.3lf) (size 0.6) (drill 0.4) (layers F.Cu B.Cu) (net 0))\n",bx,by);
        fprintf(fp,"  (gr_arc (start 150 100) (end %10.3lf %10.3lf) (angle %10.3lf) (layer F.Cu) (width 0.2))\n",ax,ay,xangle[1]);

if(min[rc]>(ra+1)) min[rc]=ra+1;
if(max[rc]<(ra+1)) max[rc]=ra+1;

        if(ra==0)
        {
            ax = xax[ra+1] * lane[9];
            ay = xay[ra+1] * lane[9];
            ax +=150.0;
            ay +=100.0;
            fprintf(fp,"  (segment (start %10.3lf %10.3lf) (end %10.3lf %10.3lf) (width 0.2) (layer F.Cu) (net 0))\n",ax,ay,bx,by);
            fprintf(fp,"  (via (at %10.3lf %10.3lf) (size 0.6) (drill 0.4) (layers F.Cu B.Cu) (net 0))\n",ax,ay);
            fprintf(fp,"  (gr_arc (start 150 100) (end %10.3lf %10.3lf) (angle %10.3lf) (layer B.Cu) (width 0.2))\n",ax,ay,xangle[3]);
            ax = xax[118] * lane[9];
            ay = xay[118] * lane[9];
            bx = xax[118] * lane[10];
            by = xay[118] * lane[10];
            ax +=150.0;
            ay +=100.0;
            bx +=150.0;
            by +=100.0;
            fprintf(fp,"  (via (at %10.3lf %10.3lf) (size 0.6) (drill 0.4) (layers F.Cu B.Cu) (net 0))\n",ax,ay);
            fprintf(fp,"  (segment (start %10.3lf %10.3lf) (end %10.3lf %10.3lf) (width 0.2) (layer F.Cu) (net 0))\n",ax,ay,bx,by);


            fprintf(fp,"  (module resi:stor (layer F.Cu) (tedit 57FE93A5) (tstamp 5AA34834) \n");
            fprintf(fp,"    (at 150 100 %5.1lf)\n",xangle[118]);
            fprintf(fp,"    (fp_text reference x (at %10.3lf 0 %3.1lf) (layer F.Fab)(effects (font (size 0.5 0.5) (thickness 0.05))))\n",lane[10]+0.0,xangle[118]);
            fprintf(fp,"    (fp_text value     x (at %10.3lf 0 %3.1lf) (layer F.Fab)(effects (font (size 0.5 0.5) (thickness 0.05))))\n",lane[10]+1.6,xangle[118]);
            fprintf(fp,"    (descr \"0603\")\n");
            fprintf(fp,"    (attr smd)\n");
            fprintf(fp,"    (pad 1 smd rect (at %5.1lf 0 %5.1lf) (size 0.8 0.8) (layers F.Cu F.Paste F.Mask))\n",lane[10]+0.0,xangle[118]);
            fprintf(fp,"    (pad 2 smd rect (at %5.1lf 0 %5.1lf) (size 0.8 0.8) (layers F.Cu F.Paste F.Mask))\n",lane[10]+1.6,xangle[118]);
            fprintf(fp,"  )\n");
            ax = xax[118] * (lane[10]+1.6);
            ay = xay[118] * (lane[10]+1.6);
            ax +=150.0;
            ay +=100.0;
            bx = xax[118] * (lane[10]+3.6);
            by = xay[118] * (lane[10]+3.6);
            bx +=150.0;
            by +=100.0;
            fprintf(fp,"  (segment (start %10.3lf %10.3lf) (end %10.3lf %10.3lf) (width 0.2) (layer F.Cu) (net 0))\n",ax,ay,bx,by);

            fprintf(fp,"  (module pin:hole (layer F.Cu) (tedit 59650532) (tstamp 5AA6FE27)\n");
            fprintf(fp,"    (at %10.3lf %10.3lf)\n",bx,by);
            fprintf(fp,"    (descr \"pinhole\")\n");
            fprintf(fp,"    (tags \"hole\")\n");
            fprintf(fp,"    (fp_text reference x (at 0 0) (layer F.Fab) (effects (font (size 0.1 0.1) (thickness 0.01))) )\n");
            fprintf(fp,"    (fp_text value     x (at 0 0) (layer F.Fab) (effects (font (size 0.1 0.1) (thickness 0.01))) )\n");
            fprintf(fp,"    (pad %u thru_hole rect (at 0 0 %3.1lf)    (size 1.7 1.7) (drill 1) (layers *.Cu *.Mask))\n",0,xangle[118]);
            fprintf(fp,"  )\n");
        }











        rd++;
        if(rd==rc)
        {
            rd++;
        }
        if(rd>8)
        {
            rc++;
            rd=0;
        }
    }



    //*********************
    // place lanes
    //*********************
    for(ra=0;ra<9;ra++)
    {

//        if(max[ra]<=min[ra])
        {
            printf("minmax %u %u %u\n",ra,min[ra],max[ra]);
        }


        switch(ra)
        {
            case 0: rc=  0; rd=119; break;
            case 1: rc=  0; rd=119; break;
            case 2: rc=  0; rd=119; break;
            case 3: rc=  0; rd=119; break;
            case 4: rc=  0; rd=119; break;
            case 5: rc=  0; rd=119; break;
            case 6: rc=  0; rd=119; break;
            case 7: rc=  0; rd=119; break;
            case 8: rc=  0; rd=119; break;
        }
        rc=min[ra];
        rd=max[ra];
        rangle=angle*degrad;
        ax = xax[rd] * lane[ra];
        ay = xay[rd] * lane[ra];
        ax += 150.0;
        ay += 100.0;
        fprintf(fp,"  (gr_arc (start 150 100) (end %10.3lf %10.3lf) (angle %10.3lf) (layer B.Cu) (width 0.2))\n",ax,ay,xangle[rd-rc]);
    }

    fprintf(fp,"  (gr_arc (start 150 100) (end %10.3lf %10.3lf) (angle %5.1lf) (layer Edge.Cuts) (width 0.15))\n",150.0+lane[11]+4.6,100.0,360.0);

    //cx=lane[11]+4.6;
    //ax=150.0-cx;
    //bx=150.0+cx;
    //ay=100.0-cx;
    //by=100.0+cx;
    //fprintf(fp,"  (gr_line (start %10.3lf %10.3lf ) (end  %10.3lf  %10.3lf ) (angle 90) (layer Edge.Cuts) (width 0.15))\n",ax,ay,ax,by);
    //fprintf(fp,"  (gr_line (start %10.3lf %10.3lf ) (end  %10.3lf  %10.3lf ) (angle 90) (layer Edge.Cuts) (width 0.15))\n",bx,ay,bx,by);
    //fprintf(fp,"  (gr_line (start %10.3lf %10.3lf ) (end  %10.3lf  %10.3lf ) (angle  0) (layer Edge.Cuts) (width 0.15))\n",ax,ay,bx,ay);
    //fprintf(fp,"  (gr_line (start %10.3lf %10.3lf ) (end  %10.3lf  %10.3lf ) (angle  0) (layer Edge.Cuts) (width 0.15))\n",ax,by,bx,by);

    fprintf(fp,"\n");
    fprintf(fp,")\n");
    fclose(fp);
    return(0);
}
