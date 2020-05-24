
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define RING_BASE 24
#define XPAD 2.7
#define YPAD 1.65
#define RPAD 0.8
#define RING_OFF 4.5
#define RING_TOP 5.5
#define RGVIA (RING_BASE-RPAD-1.1)
#define RVVIA (RING_BASE+RPAD+1.1)
//which xax/xay is 90 degrees.
#define DIVISIONS 48
#define DELTA90 (DIVISIONS/4)
#define DELTAN90 (DIVISIONS-(DIVISIONS/4))

unsigned int ninety_degrees ( unsigned int x )
{
    if(x>=DELTAN90) return(x-DELTAN90);
    return(x+DELTA90);
}

static FILE *fp;

int main ( void )
{
    double degrad;
    double angle;
    double rangle;
    double tangle;
    double gangle;
    double vangle;
    double zangle;
    double x,y;
    double ax,ay;
    double bx,by;
    double cx,cy;
    double xangle[360];
    double xax[360];
    double xay[360];



    double xgndx[360];
    double xgndy[360];
    double xvccx[360];
    double xvccy[360];


    double xinx[360];
    double xiny[360];
    double xoutx[360];
    double xouty[360];

    unsigned int ra;
    unsigned int rb;
    unsigned int rc;
    unsigned int rd;

    degrad = 1.0 / 180.0 * M_PI;

    gangle = atan(YPAD/RGVIA);
    gangle = (gangle * 180.0) / M_PI;
    vangle = atan(YPAD/RVVIA);
    vangle = (vangle * 180.0) / M_PI;
//printf("gangle %lf\n",gangle);
//printf("vangle %lf\n",vangle);

    zangle = atan(YPAD/RING_BASE);
    zangle = (zangle * 180.0) / M_PI;

    zangle = ((360.0/DIVISIONS) - zangle)*2.0;
//printf("zangle %lf\n",zangle);


    angle = 0.0;
    for(ra=0;ra<DIVISIONS;ra++,angle+=(360.0/DIVISIONS))
    {
        rangle=angle*degrad;
        x = cos(rangle);
        y = -sin(rangle);
        xangle[ra]=angle;
        xax[ra]=x;
        xay[ra]=y;

        tangle=rangle+atan(YPAD/(RING_BASE-XPAD));

        x = cos(tangle);
        y = -sin(tangle);
        xgndx[ra]=x;
        xgndy[ra]=y;

        tangle=rangle-atan(YPAD/(RING_BASE+XPAD));

        x = cos(tangle);
        y = -sin(tangle);
        xvccx[ra]=x;
        xvccy[ra]=y;


        tangle=rangle+atan(YPAD/(RING_BASE+XPAD));

        x = cos(tangle);
        y = -sin(tangle);
        xoutx[ra]=x;
        xouty[ra]=y;


        tangle=rangle-atan(YPAD/(RING_BASE-XPAD));

        x = cos(tangle);
        y = -sin(tangle);
        xinx[ra]=x;
        xiny[ra]=y;




    }


    fp=fopen("npixring.kicad_pcb","wt");
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

fprintf(fp,"  (gr_text NPIXRING%uB (at 145 100 270) (layer B.SilkS)\n",DIVISIONS/2);
fprintf(fp,"    (effects (font (size 1.5 1.5) (thickness 0.3))(justify mirror) )\n");
fprintf(fp,"  )\n");




    //place fab reference lines/numbers
    for(ra=0;ra<DIVISIONS;ra++)
    {
        ax = xax[ra] * (RING_BASE-10);
        ay = xay[ra] * (RING_BASE-10);
        bx = xax[ra] * (RING_BASE+10);
        by = xay[ra] * (RING_BASE+10);
        cx = xax[ra] * (RING_BASE+12);
        cy = xay[ra] * (RING_BASE+12);
        ax +=150.0;
        ay +=100.0;
        bx +=150.0;
        by +=100.0;
        cx +=150.0;
        cy +=100.0;
        fprintf(fp,"  (gr_line (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (angle %10.5lf) (layer F.Fab) (width 0.05))\n",ax,ay,bx,by,xangle[ra]);
        fprintf(fp,"  (gr_text \" %u %3.1lf\" (at %10.5lf %10.5lf %10.5lf) (layer F.Fab)(effects (font (size 0.5 0.5) (thickness 0.1))) )\n",ra,xangle[ra],cx,cy,xangle[ra]);
    }


    fprintf(fp,"  (module head:pin (layer B.Cu) (tedit 0) (tstamp 5EAFD035)\n");
    fprintf(fp,"    (at 150 100)\n");
    //fprintf(fp,"\n");
    //fprintf(fp,"    (fp_text reference \"\" (at 0 0) (layer F.Fab)(effects (font (size 0.5 0.5) (thickness 0.05))))\n");
    //fprintf(fp,"    (fp_text value     \"\" (at 0 0) (layer F.Fab)(effects (font (size 0.5 0.5) (thickness 0.05))))\n");
    //fprintf(fp,"    (descr header)\n");
    //fprintf(fp,"    (attr header)\n");
//    fprintf(fp,"\n");
//    fprintf(fp,"    (fp_text reference \"\" (at 0 -2.4) (layer B.SilkS) (effects (font (size 0.5 0.5) (thickness 0.01)))  )\n");
//    fprintf(fp,"    (fp_text value \"\" (at 0 -3.1) (layer F.Fab) (effects (font (size 0.5 0.5) (thickness 0.01)))  )\n");
    fprintf(fp,"    (pad x thru_hole oval (at 0 0) (size 1.8 1.8) (drill 1.016) (layers *.Cu *.Mask B.SilkS))\n");
    fprintf(fp,"  )\n");

    ax = xax[0] * (RING_BASE-RING_TOP-2);
    ay = xay[0] * (RING_BASE-RING_TOP-2);
    ax +=150.0;
    ay +=100.0;

    fprintf(fp,"(gr_text V (at %10.5lf %10.5lf 270) (layer B.SilkS)(effects (font (size 1 1) (thickness 0.15))(justify mirror)))\n",ax-3.0,ay-2.54);
    fprintf(fp,"(gr_text I (at %10.5lf %10.5lf 270) (layer B.SilkS)(effects (font (size 1 1) (thickness 0.15))(justify mirror)))\n",ax-3.0,ay+0.00);
    fprintf(fp,"(gr_text G (at %10.5lf %10.5lf 270) (layer B.SilkS)(effects (font (size 1 1) (thickness 0.15))(justify mirror)))\n",ax-3.0,ay+2.54);

    fprintf(fp,"  (module head:er (layer B.Cu) (tedit 0) (tstamp 5EAFD035)\n");
    fprintf(fp,"    (at %10.5lf %10.5lf)\n",ax,ay);
    //fprintf(fp,"\n");
    //fprintf(fp,"    (fp_text reference \"\" (at 0 0) (layer F.Fab)(effects (font (size 0.5 0.5) (thickness 0.05))))\n");
    //fprintf(fp,"    (fp_text value     \"\" (at 0 0) (layer F.Fab)(effects (font (size 0.5 0.5) (thickness 0.05))))\n");
    //fprintf(fp,"    (descr header)\n");
    //fprintf(fp,"    (attr header)\n");
//    fprintf(fp,"\n");
//    fprintf(fp,"    (fp_text reference \"\" (at 0 -2.4) (layer B.SilkS) (effects (font (size 0.5 0.5) (thickness 0.01)))  )\n");
//    fprintf(fp,"    (fp_text value \"\" (at 0 -3.1) (layer F.Fab) (effects (font (size 0.5 0.5) (thickness 0.01)))  )\n");
    fprintf(fp,"    (fp_line (start -1.75 -4.29) (end -1.75 4.29) (layer F.CrtYd) (width 0.05))\n");
    fprintf(fp,"    (fp_line (start 1.75 -4.29) (end 1.75 4.29) (layer F.CrtYd) (width 0.05))\n");
    fprintf(fp,"    (fp_line (start -1.75 -4.29) (end 1.75 -4.29) (layer F.CrtYd) (width 0.05))\n");
    fprintf(fp,"    (fp_line (start -1.75 4.29) (end 1.75 4.29) (layer F.CrtYd) (width 0.05))\n");
    fprintf(fp,"    (fp_line (start -6 -2.54) (end 6 -2.54) (layer F.CrtYd) (width 0.01))\n");
    fprintf(fp,"    (fp_line (start -6 0) (end 6 0) (layer F.CrtYd) (width 0.01))\n");
    fprintf(fp,"    (fp_line (start -6 2.54) (end 6 2.54) (layer F.CrtYd) (width 0.01))\n");
    fprintf(fp,"    (pad 1 thru_hole oval (at 0 -2.54) (size 1.8 1.8) (drill 1.016) (layers *.Cu *.Mask B.SilkS))\n");
    fprintf(fp,"    (pad 2 thru_hole oval (at 0 0) (size 1.8 1.8) (drill 1.016) (layers *.Cu *.Mask B.SilkS))\n");
    fprintf(fp,"    (pad 3 thru_hole oval (at 0 2.54) (size 1.8 1.8) (drill 1.016) (layers *.Cu *.Mask B.SilkS))\n");
    fprintf(fp,"  )\n");

    ////place leds
    //rc=0; rd=1;
    for(ra=0;ra<DIVISIONS;ra+=2)
    {
        fprintf(fp,"  (module min:hand (layer B.Cu) (tedit 57FE93A5) (tstamp 5AA34834)\n");
        fprintf(fp,"    (at  %10.5lf %10.5lf %10.5lf)\n",150+xax[ra]*RING_BASE,100+xay[ra]*RING_BASE,xangle[ra]);
        //fprintf(fp,"    (fp_text reference \"\" (at 0 0) (layer F.Fab)(effects (font (size 0.5 0.5) (thickness 0.05))))\n");
        //fprintf(fp,"    (fp_text value     \"\" (at 0 0) (layer F.Fab)(effects (font (size 0.5 0.5) (thickness 0.05))))\n");
        //fprintf(fp,"    (descr \"0603\")\n");
        //fprintf(fp,"    (attr smd)\n");
        fprintf(fp,"    (pad V smd rect (at -0.8 0 %10.5lf) (size 0.8 0.8) (layers B.Cu B.Paste B.Mask))\n",xangle[ra]);
        fprintf(fp,"    (pad G smd rect (at +0.8 0 %10.5lf) (size 0.8 0.8) (layers B.Cu B.Paste B.Mask))\n",xangle[ra]);
        fprintf(fp,"  )\n");

        fprintf(fp,"(module 00_my_modules:X (layer F.Cu) (tedit 5415CC62) (tstamp 5EA86CD9)\n");
        fprintf(fp,"    (at  %10.5lf %10.5lf %10.5lf)\n",150+xax[ra]*RING_BASE,100+xay[ra]*RING_BASE,xangle[ra]+180);
        //fprintf(fp,"    (descr WS2812B)\n");
        //fprintf(fp,"    (attr smd)\n");
        //fprintf(fp,"    (fp_text reference \"\" (at 0 0) (layer F.Fab)(effects (font (size 0.5 0.5) (thickness 0.05))))\n");
        //fprintf(fp,"    (fp_text value     \"\" (at 0 0) (layer F.Fab)(effects (font (size 0.5 0.5) (thickness 0.05))))\n");
        fprintf(fp,"    (fp_line (start 2.5 2.5) (end -2.5 2.5) (layer B.CrtYd) (width 0.01))\n");
        fprintf(fp,"    (fp_line (start 2.5 -2.5) (end -2.5 -2.5) (layer B.CrtYd) (width 0.01))\n");
        fprintf(fp,"    (fp_line (start 2.5 2.5) (end 2.5 -2.5) (layer B.CrtYd) (width 0.01))\n");
        fprintf(fp,"    (fp_line (start -2.5 2.5) (end -2.5 -2.5) (layer B.CrtYd) (width 0.01))\n");
        fprintf(fp,"    (fp_line (start -1.5 -2.5) (end -2.5 -1.5) (layer B.CrtYd) (width 0.01))\n");
        fprintf(fp,"    (fp_line (start 2.65 0.5) (end 2.65 -0.5) (layer F.SilkS) (width 0.1))\n");

        //fprintf(fp,"    (fp_line (start -3.8 -1.65) (end -1.6 -1.65) (layer B.CrtYd) (width 0.01))\n");
        //fprintf(fp,"    (fp_line (start -2.7 -2.65) (end -2.7 -0.65) (layer B.CrtYd) (width 0.01))\n");

        //fprintf(fp,"    (fp_line (start  3.8  1.65) (end  1.6  1.65) (layer B.CrtYd) (width 0.01))\n");
        //fprintf(fp,"    (fp_line (start  2.7  2.65) (end  2.7  0.65) (layer B.CrtYd) (width 0.01))\n");

        fprintf(fp,"    (pad VCC smd rect (at  2.7  1.65 %10.5lf) (size 2 0.9) (layers F.Cu F.Paste F.Mask))\n",xangle[ra]);
        fprintf(fp,"    (pad OUT smd rect (at  2.7 -1.65 %10.5lf) (size 2 0.9) (layers F.Cu F.Paste F.Mask))\n",xangle[ra]);
        fprintf(fp,"    (pad GND smd rect (at -2.7 -1.65 %10.5lf) (size 2 0.9) (layers F.Cu F.Paste F.Mask))\n",xangle[ra]);
        fprintf(fp,"    (pad  IN smd rect (at -2.7  1.65 %10.5lf) (size 2 0.9) (layers F.Cu F.Paste F.Mask))\n",xangle[ra]);
        fprintf(fp,"  )\n");

        //ground connection to ring
        {
            ax = xgndx[ra] * (RING_BASE-RING_OFF);
            ay = xgndy[ra] * (RING_BASE-RING_OFF);
            bx = xgndx[ra] * (RING_BASE-XPAD);
            by = xgndy[ra] * (RING_BASE-XPAD);
            ax +=150.0;
            ay +=100.0;
            bx +=150.0;
            by +=100.0;
            fprintf(fp,"  (segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.2) (layer F.Cu) )\n",ax,ay,bx,by);
            if(ra==0)
            {
                ax = xax[ra+1] * (RING_BASE-RING_OFF);
                ay = xay[ra+1] * (RING_BASE-RING_OFF);
                ax +=150.0;
                ay +=100.0;
                bx = xax[ra+1] * (RING_BASE-RING_TOP-1.5);
                by = xay[ra+1] * (RING_BASE-RING_TOP-1.5);
                bx +=150.0;
                by +=100.0;
                fprintf(fp,"  (segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.2) (layer F.Cu) )\n",ax,ay,bx,by);
            }
        }

        //vcc connection to ring
        {
            ax = xvccx[ra] * (RING_BASE+RING_OFF);
            ay = xvccy[ra] * (RING_BASE+RING_OFF);
            bx = xvccx[ra] * (RING_BASE+XPAD);
            by = xvccy[ra] * (RING_BASE+XPAD);
            ax +=150.0;
            ay +=100.0;
            bx +=150.0;
            by +=100.0;
            fprintf(fp,"  (segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.2) (layer F.Cu) )\n",ax,ay,bx,by);
            if(ra==(DIVISIONS-2))
            {
                ax = xax[ra+1] * (RING_BASE-1);
                ay = xay[ra+1] * (RING_BASE-1);
                bx = xax[ra+1] * (RING_BASE-RING_TOP-1.5);
                by = xay[ra+1] * (RING_BASE-RING_TOP-1.5);
                ax +=150.0;
                ay +=100.0;
                bx +=150.0;
                by +=100.0;
                fprintf(fp,"  (segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.2) (layer F.Cu) )\n",ax,ay,bx,by);
                fprintf(fp,"  (via (at %10.5lf %10.5lf) (size 0.6) (drill 0.4) (layers F.Cu B.Cu) )\n",ax,ay);

                ax = xax[ra+1] * (RING_BASE+1);
                ay = xay[ra+1] * (RING_BASE+1);
                bx = xax[ra+1] * (RING_BASE-1);
                by = xay[ra+1] * (RING_BASE-1);
                ax +=150.0;
                ay +=100.0;
                bx +=150.0;
                by +=100.0;
                fprintf(fp,"  (segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.2) (layer B.Cu) )\n",ax,ay,bx,by);
                fprintf(fp,"  (via (at %10.5lf %10.5lf) (size 0.6) (drill 0.4) (layers F.Cu B.Cu) )\n",ax,ay);

                ax = xax[ra+1] * (RING_BASE+RING_OFF);
                ay = xay[ra+1] * (RING_BASE+RING_OFF);
                bx = xax[ra+1] * (RING_BASE+1);
                by = xay[ra+1] * (RING_BASE+1);
                ax +=150.0;
                ay +=100.0;
                bx +=150.0;
                by +=100.0;
                fprintf(fp,"  (segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.2) (layer F.Cu) )\n",ax,ay,bx,by);
            }
        }


        //hook up out to in
        {
            if(ra==0)
            {
                ax = xax[ra] * (RING_BASE+XPAD);
                ay = xay[ra] * (RING_BASE+XPAD);
                ax +=150.0;
                ay +=100.0;

                bx = xax[ra] * (RING_BASE-RING_TOP-1.5);
                by = xay[ra] * (RING_BASE-RING_TOP-1.5);
                bx +=150.0;
                by +=100.0;

                fprintf(fp,"  (segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.2) (layer F.Cu) )\n",ax,ay,bx,by);

                ax = xax[ra] * (RING_BASE+XPAD);
                ay = xay[ra] * (RING_BASE+XPAD);
                ax +=150.0;
                ay +=100.0;

                bx = xax[ra] * (RING_BASE+XPAD);
                by = xay[ra] * (RING_BASE+XPAD);
                bx += xax[ninety_degrees(ra)] * YPAD;
                by += xay[ninety_degrees(ra)] * YPAD;
                bx +=150.0;
                by +=100.0;
                fprintf(fp,"  (segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.2) (layer F.Cu) )\n",ax,ay,bx,by);
            }
            if(ra!=2)
            {
                ax = xinx[ra] * (RING_BASE-XPAD);
                ay = xiny[ra] * (RING_BASE-XPAD);
                ax +=150.0;
                ay +=100.0;
                bx = xax[ra] * (RING_BASE);
                by = xay[ra] * (RING_BASE);
                bx -= xax[ninety_degrees(ra)] * YPAD;
                by -= xay[ninety_degrees(ra)] * YPAD;
                bx +=150.0;
                by +=100.0;
                fprintf(fp,"  (segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.2) (layer F.Cu) )\n",ax,ay,bx,by);
                fprintf(fp,"  (gr_arc (start 150 100) (end %10.5lf %10.5lf) (angle %10.5lf) (layer F.Cu) (width 0.2) )\n",bx,by,zangle);
            }


            ax = xoutx[ra] * (RING_BASE+XPAD);
            ay = xouty[ra] * (RING_BASE+XPAD);
            ax +=150.0;
            ay +=100.0;
            bx = xax[ra] * (RING_BASE);
            by = xay[ra] * (RING_BASE);
            bx += xax[ninety_degrees(ra)] * YPAD;
            by += xay[ninety_degrees(ra)] * YPAD;
            bx +=150.0;
            by +=100.0;
            if(ra==0)
            {
            }
            else
            {
                fprintf(fp,"  (segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.2) (layer F.Cu) )\n",ax,ay,bx,by);
            }
        }


        //connect capacitor
        {
            //gnd side
            ax = xax[ra] * (RING_BASE-RPAD);
            ay = xay[ra] * (RING_BASE-RPAD);
            bx = xax[ra] * (RING_BASE-RPAD);
            by = xay[ra] * (RING_BASE-RPAD);
            bx += xax[ninety_degrees(ra)] * YPAD;
            by += xay[ninety_degrees(ra)] * YPAD;
            ax +=150.0;
            ay +=100.0;
            bx +=150.0;
            by +=100.0;
            fprintf(fp,"  (segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.2) (layer B.Cu) )\n",ax,ay,bx,by);
            fprintf(fp,"  (via (at %10.5lf %10.5lf) (size 0.6) (drill 0.4) (layers F.Cu B.Cu) )\n",bx,by);
            ax = xgndx[ra] * (RING_BASE-XPAD);
            ay = xgndy[ra] * (RING_BASE-XPAD);
            ax +=150.0;
            ay +=100.0;
            fprintf(fp,"  (segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.2) (layer F.Cu) )\n",ax,ay,bx,by);


            //vcc side
            ax = xax[ra] * (RING_BASE+RPAD);
            ay = xay[ra] * (RING_BASE+RPAD);
            bx = xax[ra] * (RING_BASE+RPAD);
            by = xay[ra] * (RING_BASE+RPAD);
            bx -= xax[ninety_degrees(ra)] * YPAD;
            by -= xay[ninety_degrees(ra)] * YPAD;
            ax +=150.0;
            ay +=100.0;
            bx +=150.0;
            by +=100.0;
            fprintf(fp,"  (segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.2) (layer B.Cu) )\n",ax,ay,bx,by);
            fprintf(fp,"  (via (at %10.5lf %10.5lf) (size 0.6) (drill 0.4) (layers F.Cu B.Cu) )\n",bx,by);
            ax = xvccx[ra] * (RING_BASE+XPAD);
            ay = xvccy[ra] * (RING_BASE+XPAD);
            ax +=150.0;
            ay +=100.0;
            fprintf(fp,"  (segment (start %10.5lf %10.5lf) (end %10.5lf %10.5lf) (width 0.2) (layer F.Cu) )\n",ax,ay,bx,by);
        }

    }

    ax = xgndx[DIVISIONS-2] * (RING_BASE-RING_OFF);
    ay = xgndy[DIVISIONS-2] * (RING_BASE-RING_OFF);
    ax += 150.0;
    ay += 100.0;
    fprintf(fp,"  (gr_arc (start 150 100) (end %10.5lf %10.5lf) (angle %10.5lf) (layer F.Cu) (width 0.2))\n",ax,ay,xangle[DIVISIONS-2]);

    ax = xvccx[0] * (RING_BASE+RING_OFF);
    ay = xvccy[0] * (RING_BASE+RING_OFF);
    ax += 150.0;
    ay += 100.0;
    fprintf(fp,"  (gr_arc (start 150 100) (end %10.5lf %10.5lf) (angle %10.5lf) (layer F.Cu) (width 0.2))\n",ax,ay,xangle[DIVISIONS-2]);


    ax = xax[0] * (RING_BASE);
    ay = xay[0] * (RING_BASE);
    ax += 150.0;
    ay += 100.0;
//    fprintf(fp,"  (gr_arc (start 150 100) (end %10.5lf %10.5lf) (angle %10.5lf) (layer F.Fab) (width 0.2))\n",ax,ay,xangle[58]);



    ////fprintf(fp,"  (gr_arc (start 150 100) (end %10.5lf %10.5lf) (angle %10.5lf) (layer Edge.Cuts) (width 0.15))\n",150.0+lane[9],100.0,360.0);

    //cx=lane[9];
    ax=150.0-(RING_BASE+7);
    bx=150.0+(RING_BASE+7);
    ay=100.0-(RING_BASE+7);
    by=100.0+(RING_BASE+7);
    fprintf(fp,"  (gr_line (start %10.5lf %10.5lf ) (end  %10.5lf  %10.5lf ) (angle 90) (layer Edge.Cuts) (width 0.15))\n",ax,ay,ax,by);
    fprintf(fp,"  (gr_line (start %10.5lf %10.5lf ) (end  %10.5lf  %10.5lf ) (angle 90) (layer Edge.Cuts) (width 0.15))\n",bx,ay,bx,by);
    fprintf(fp,"  (gr_line (start %10.5lf %10.5lf ) (end  %10.5lf  %10.5lf ) (angle  0) (layer Edge.Cuts) (width 0.15))\n",ax,ay,bx,ay);
    fprintf(fp,"  (gr_line (start %10.5lf %10.5lf ) (end  %10.5lf  %10.5lf ) (angle  0) (layer Edge.Cuts) (width 0.15))\n",ax,by,bx,by);

    fprintf(fp,"\n");
    fprintf(fp,")\n");
    fclose(fp);
    return(0);
}
