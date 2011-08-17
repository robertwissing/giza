/* giza - a scientific plotting layer built on cairo
 *
 * This file is (or was) part of GIZA, a scientific plotting
 * layer built on cairo.
 * GIZA comes with ABSOLUTELY NO WARRANTY.
 * This is free software; and you are welcome to redistribute
 * it under the terms of the GNU General Public License
 * (see LICENSE file for details) and the provision that
 * this notice remains intact. If you modify this file, please
 * note section 2a) of the GPLv2 states that:
 *
 *  a) You must cause the modified files to carry prominent notices
 *     stating that you changed the files and the date of any change.
 *
 * Copyright (C) 2010 James Wetter and Daniel Price. All rights reserved.
 * Contact: wetter.j@gmail.com
 *          daniel.price@monash.edu
 *
 */
 
/*
 *  This file contains the cpgplot interface to giza
 *  so that giza can be used as a drop-in replacement
 *  for the cpgplot library
 *
 */

#include "giza.h"
#include "cpgplot.h"
#include <string.h>
int pgfont;

/***************************************************************
 * Function to convert PGPLOT units value to giza units value
 ***************************************************************/
int units_giza(int pgplotunits)
{
  int units;
  switch (pgplotunits)
  {
  case 0:
     units = GIZA_UNITS_NORMALIZED;
     break;
  case 1:
     units = GIZA_UNITS_INCHES;
     break;
  case 2:
     units = GIZA_UNITS_MM;
     break;
  case 3:
     units = GIZA_UNITS_PIXELS;
     break;
  case 4:
     units = GIZA_UNITS_WORLD;
     break;
  default: /* giza will give an error */
     units = pgplotunits;
     break;
  }
  
  return units;
}

/***************************************************************
 * Routine to convert PGPLOT "trans" array to giza "affine" array
 ***************************************************************/
void convert_tr_to_affine(const float *tr, float *affine)
{
  affine[0] = tr[1];
  affine[1] = tr[2];
  affine[2] = tr[4];
  affine[3] = tr[5];
  affine[4] = tr[0] + 0.5f*(tr[1]);
  affine[5] = tr[3] + 0.5f*(tr[5]);
}

/***************************************************************
 * cpgarro -- draw an arrow
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgarro(float x1, float y1, float x2, float y2)
{
  giza_arrow_float(x1,y1,x2,y2);
}

/***************************************************************
 * cpgask -- control new page prompting
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgask(Logical flag)
{
  if (flag) {
    giza_start_prompting();
  } else {
    giza_stop_prompting();
  }

}

/***************************************************************
 * cpgaxis -- draw an axis
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgaxis(const char *opt, float x1, float y1, float x2, float y2, \
             float v1, float v2, float step, int nsub, float dmajl, \
             float dmajr, float fmin, float disp, float orient)
{

}

/***************************************************************
 * cpgband -- read cursor position, with anchor
 * Status: IMPLEMENTED
 ***************************************************************/
int cpgband(int mode, int posn, float xref, float yref, float *x,\
            float *y, char *ch_scalar)
{
   return giza_band_float(mode,posn,xref,yref,x,y,ch_scalar);
}

/***************************************************************
 * cpgbbuf -- begin batch of output (buffer)
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgbbuf(void)
{
  giza_begin_buffer();
}

/***************************************************************
 * cpgbeg -- open a graphics device
 * Status: PARTIALLY IMPLEMENTED
 ***************************************************************/
int cpgbeg(int unit, const char *file, int nxsub, int nysub)
{
  return cpgopen(file);
}

/***************************************************************
 * cpgbin -- histogram of binned data
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgbin(int nbin, const float *x, const float *data, \
 Logical center)
{

}

/***************************************************************
 * cpgbox -- draw labeled frame around viewport
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgbox(const char *xopt, float xtick, int nxsub, \
 const char *yopt, float ytick, int nysub)
{
  giza_box(xopt, xtick, nxsub, yopt, ytick, nysub);
}

/***************************************************************
 * cpgcirc -- draw a circle, using fill-area attributes
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgcirc(float xcent, float ycent, float radius)
{
  giza_circle_float(xcent,ycent,radius);
}

/***************************************************************
 * cpgclos -- close the selected graphics device
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgclos(void)
{
  giza_close_device();
}

/***************************************************************
 * cpgconb -- contour map of a 2D data array, with blanking
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgconb(const float *a, int idim, int jdim, int i1, int i2, \
 int j1, int j2, const float *c, int nc, const float *tr, \
 float blank)
{
  float affine[6];
  convert_tr_to_affine(tr,affine);
/*  giza_contour_float(idim,jdim,a,i1-1,i2-1,j1-1,j2-1,abs(nc),c,affine);
*/
}

/***************************************************************
 * cpgconf -- fill between two contours
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgconf(const float *a, int idim, int jdim, int i1, int i2, \
 int j1, int j2, float c1, float c2, const float *tr)
{

}

/***************************************************************
 * cpgconl -- label contour map of a 2D data array
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgconl(const float *a, int idim, int jdim, int i1, int i2, \
 int j1, int j2, float c, const float *tr, const char *label, \
 int intval, int minint)
{
  float affine[6];
  convert_tr_to_affine(tr,affine);
/*  giza_contour_float(idim,jdim,a,i1-1,i2-1,j1-1,j2-1,abs(nc),c,affine);*/

}

/***************************************************************
 * cpgcons -- contour map of a 2D data array (fast algorithm)
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgcons(const float *a, int idim, int jdim, int i1, int i2, \
 int j1, int j2, const float *c, int nc, const float *tr)
{
  float affine[6];
  convert_tr_to_affine(tr,affine);
/*  giza_contour_float(idim,jdim,a,i1-1,i2-1,j1-1,j2-1,abs(nc),c,affine);*/
}

/***************************************************************
 * cpgcont -- contour map of a 2D data array (contour-following)
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgcont(const float *a, int idim, int jdim, int i1, int i2, \
 int j1, int j2, const float *c, int nc, const float *tr)
{
  float affine[6];
  convert_tr_to_affine(tr,affine);
/*  giza_contour_float(idim,jdim,a,i1-1,i2-1,j1-1,j2-1,abs(nc),c,affine);*/
}

/***************************************************************
 * cpgctab -- install the color table to be used by pgimag
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgctab(const float *l, const float *r, const float *g, \
 const float *b, int nc, float contra, float bright)
{
   giza_set_colour_table_float(l,r,g,b,nc);
}

/***************************************************************
 * cpgcurs -- read cursor position
 * Status: IMPLEMENTED
 ***************************************************************/
int cpgcurs(float *x, float *y, char *ch_scalar)
{
   return giza_get_key_press_float(x,y,ch_scalar);
}

/***************************************************************
 * cpgdraw -- draw a line from the current pen position to a point
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgdraw(float x, float y)
{
   giza_draw_float(x, y);
}

/***************************************************************
 * cpgebuf -- end batch of output (buffer)
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgebuf(void)
{
   giza_end_buffer();
}

/***************************************************************
 * cpgend -- close all open graphics devices
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgend(void)
{
   giza_close_device();
}

/***************************************************************
 * cpgenv -- set window and viewport and draw labeled frame
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgenv(float xmin, float xmax, float ymin, float ymax, \
 int just, int axis)
{
  giza_set_environment_float(xmin, xmax, ymin, ymax, just, axis);
}

/***************************************************************
 * cpgeras -- erase all graphics from current page
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgeras(void)
{
  giza_draw_background();
}

/***************************************************************
 * cpgerr1 -- horizontal or vertical error bar
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgerr1(int dir, float x, float y, float e, float t)
{
  float xi[1], yi[1], ei[1];
  xi[0] = x;
  yi[0] = y;
  ei[0] = e;
  cpgerrb(dir, 1, xi, yi, ei, t);
}

/***************************************************************
 * cpgerrb -- horizontal or vertical error bar
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgerrb(int dir, int n, const float *x, const float *y, \
 const float *e, float t)
{
  giza_error_bars_float(dir, n, x, y, e, t);
}

/***************************************************************
 * cpgerrx -- horizontal error bar
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgerrx(int n, const float *x1, const float *x2, \
 const float *y, float t)
{
  giza_error_bars_hori_float(n, x1, x2, y, t);
}

/***************************************************************
 * cpgerry -- vertical error bar
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgerry(int n, const float *x, const float *y1, \
 const float *y2, float t)
{
  giza_error_bars_vert_float(n, x, y1, y2, t);
}

/***************************************************************
 * cpgetxt -- erase text from graphics display
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgetxt(void)
{

}

/***************************************************************
 * cpgfunt -- function defined by x = f(t), y = g(t)
 ***************************************************************/

/***************************************************************
 * cpgfunx -- function defined by y = f(x)
 ***************************************************************/

/***************************************************************
 * cpgfuny -- function defined by x = f(y)
 ***************************************************************/

/***************************************************************
 * cpggray -- gray-scale map of a 2D data array
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpggray(const float *a, int idim, int jdim, int i1, int i2, \
 int j1, int j2, float fg, float bg, const float *tr)
{

}

/***************************************************************
 * cpghi2D -- cross-sections through a 2D data array
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpghi2D(const float *data, int nxv, int nyv, int ix1, \
 int ix2, int iy1, int iy2, const float *x, int ioff, float bias, \
 Logical center, float *ylims)
{

}

/***************************************************************
 * cpghist -- histogram of unbinned data
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpghist(int n, const float *data, float datmin, float datmax, \
 int nbin, int pgflag)
{

}

/***************************************************************
 * cpgiden -- write username, date, and time at bottom of plot
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgiden(void)
{
  giza_print_id();
}

/***************************************************************
 * cpgimag -- color image from a 2D data array
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgimag(const float *a, int idim, int jdim, int i1, int i2, \
 int j1, int j2, float a1, float a2, const float *tr)
{

}

/***************************************************************
 * cpglab -- write labels for x-axis, y-axis, and top of plot
 * Status: IMPLEMENTED
 ***************************************************************/
void cpglab(const char *xlbl, const char *ylbl, const char *toplbl)
{
  giza_label(xlbl, ylbl, toplbl);
}

/***************************************************************
 * cpglcur -- draw a line using the cursor
 * Status: IMPLEMENTED
 ***************************************************************/
void cpglcur(int maxpt, int *npt, float *x, float *y)
{
  giza_mark_line_float(maxpt, npt, x, y);
}

/***************************************************************
 * cpgldev -- list available device types on standard output
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgldev(void)
{
  giza_print_device_list();
}

/***************************************************************
 * cpglen -- find length of a string in a variety of units
 * Status: IMPLEMENTED
 ***************************************************************/
void cpglen(int units, const char *string, float *xl, float *yl)
{
  giza_qtextlen_float(units_giza(units),string,xl,yl);
}

/***************************************************************
 * cpgline -- draw a polyline (curve defined by line-segments)
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgline(int n, const float *xpts, const float *ypts)
{
  giza_line_float(n, xpts, ypts);
}

/***************************************************************
 * cpgmove -- move pen (change current pen position)
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgmove(float x, float y)
{
  giza_move_float(x, y);
}

/***************************************************************
 * cpgmtxt -- write text at position relative to viewport
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgmtxt(const char *side, float disp, float coord, \
 float fjust, const char *text)
{
  giza_annotate_float(side, disp, coord, fjust, text);
}

/***************************************************************
 * cpgncur -- mark a set of points using the cursor
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgncur(int maxpt, int *npt, float *x, float *y, int symbol)
{
  giza_mark_points_ordered_float(maxpt, npt, x, y, symbol);
}

/***************************************************************
 * cpgnumb -- convert a number into a plottable character string
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgnumb(int mm, int pp, int form, char *string, \
 int *string_length)
{
  giza_format_number(mm, pp, form, string);
  *string_length = strlen(string);
}

/***************************************************************
 * cpgolin -- mark a set of points using the cursor
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgolin(int maxpt, int *npt, float *x, float *y, int symbol)
{
  giza_mark_points_float(maxpt, npt, x, y, symbol);
}

/***************************************************************
 * cpgopen -- open a graphics device
 * Status: IMPLEMENTED
 ***************************************************************/
int cpgopen(const char *device)
{
  int pgopen = giza_open_device(device,"giza");
 
 /*  PGPLOT gets pgopen = id on success
  *  and <= 0 for errors
  */
 if (pgopen!=0) {
    pgopen = -1;
 } else {
    pgopen = 1;
 }
 return pgopen;

}

/***************************************************************
 * cpgpage -- advance to new page
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgpage(void)
{
  giza_change_page();
}

/***************************************************************
 * cpgpanl -- switch to a different panel on the view surface
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgpanl(int nxc, int nyc)
{

}

/***************************************************************
 * cpgpap -- change the size of the view surface
 * Status: IMPLEMENTED (NOT WORKING)
 ***************************************************************/
void cpgpap(float width, float aspect)
{
 
 float widthCM = width * 2.54;  /* convert to cm */
 giza_set_paper_size_float(widthCM,aspect);

}

/***************************************************************
 * cpgpixl -- draw pixels
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgpixl(const int *ia, int idim, int jdim, int i1, int i2, \
 int j1, int j2, float x1, float x2, float y1, float y2)
{

}

/***************************************************************
 * cpgpnts -- draw several graph markers, not all the same
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgpnts(int n, const float *x, const float *y, \
 const int *symbol, int ns)
{

}

/***************************************************************
 * cpgpoly -- draw a polygon, using fill-area attributes
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgpoly(int n, const float *xpts, const float *ypts)
{
  giza_polygon_float(n, xpts, ypts);
}

/***************************************************************
 * cpgpt -- draw several graph markers
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgpt(int n, const float *xpts, const float *ypts, int symbol)
{
  giza_points_float(n, xpts, ypts, symbol);
}

/***************************************************************
 * cpgpt1 -- draw one graph marker
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgpt1(float xpt, float ypt, int symbol)
{
  giza_single_point_float(xpt, ypt, symbol);
}

/***************************************************************
 * cpgptxt -- write text at arbitrary position and angle
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgptxt(float x, float y, float angle, float fjust, \
 const char *text)
{
  giza_ptext_float(x, y, angle, fjust, text);
}

/***************************************************************
 * cpgqah -- inquire arrow-head style
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgqah(int *fs, float *angle, float *barb)
{
  giza_get_arrow_style_float(fs, angle, barb);
}

/***************************************************************
 * cpgqcf -- inquire character font
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgqcf(int *font)
{
  /* pgfont set by call to cpgscf */
  *font = pgfont;
}

/***************************************************************
 * cpgqch -- inquire character height
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgqch(float *size)
{
  giza_get_character_height_float(size);
}

/***************************************************************
 * cpgqci -- inquire color index
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgqci(int *ci)
{
  giza_get_colour_index(ci);
}

/***************************************************************
 * cpgqcir -- inquire color index range
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgqcir(int *icilo, int *icihi)
{
  giza_get_colour_index_range(icilo, icihi);
}

/***************************************************************
 * cpgqclp -- inquire clipping Status
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgqclp(int *state)
{
  giza_get_clipping(state);
}

/***************************************************************
 * cpgqcol -- inquire color capability
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgqcol(int *ci1, int *ci2)
{
  *ci1 = GIZA_COLOUR_INDEX_MIN;
  *ci2 = GIZA_COLOUR_INDEX_MAX;
}

/***************************************************************
 * cpgqcr -- inquire color representation
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgqcr(int ci, float *cr, float *cg, float *cb)
{
  giza_get_colour_representation_float(ci,cr,cg,cb);
}

/***************************************************************
 * cpgqcs -- inquire character height in a variety of units
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgqcs(int units, float *xch, float *ych)
{
  giza_get_character_size_float(units_giza(units),xch,ych);
}

/***************************************************************
 * cpgqdt -- inquire name of nth available device type
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgqdt(int n, char *type, int *type_length, char *descr, \
 int *descr_length, int *inter)
{

}

/***************************************************************
 * cpgqfs -- inquire fill-area style
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgqfs(int *fs)
{
  giza_get_fill(fs);
}

/***************************************************************
 * cpgqhs -- inquire hatching style
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgqhs(float *angle, float *sepn, float* phase)
{
  giza_get_hatching_style_float(angle,sepn,phase);
}

/***************************************************************
 * cpgqid -- inquire current device identifier
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgqid(int *id)
{
  *id = 1;
}

/***************************************************************
 * cpgqinf -- inquire pgplot general information
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgqinf(const char *item, char *value, int *value_length)
{

}

/***************************************************************
 * cpgqitf -- inquire image transfer function
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgqitf(int *itf)
{

}

/***************************************************************
 * cpgqls -- inquire line style
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgqls(int *ls)
{
  giza_get_line_style(ls);
}

/***************************************************************
 * cpgqlw -- inquire line width
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgqlw(int *lw)
{
  giza_get_line_width(lw);
}

/***************************************************************
 * cpgqndt -- inquire number of available device types
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgqndt(int *n)
{

}

/***************************************************************
 * cpgqpos -- inquire current pen position
 * Status: IMPLEMENTED
 ***************************************************************/
void cpgqpos(float *x, float *y)
{
  giza_get_current_point_float(x, y);
}

/***************************************************************
 * cpgqtbg -- inquire text background color index
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgqtbg(int *tbci)
{

}

/***************************************************************
 * cpgqtxt -- find bounding box of text string
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgqtxt(float x, float y, float angle, float fjust, \
 const char *text, float *xbox, float *ybox)
{

}

/***************************************************************
 * cpgqvp -- inquire viewport size and position
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgqvp(int units, float *x1, float *x2, float *y1, float *y2)
{

}

/***************************************************************
 * cpgqvsz -- inquire size of view surface
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgqvsz(int units, float *x1, float *x2, float *y1, float *y2)
{

}

/***************************************************************
 * cpgqwin -- inquire window boundary coordinates
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgqwin(float *x1, float *x2, float *y1, float *y2)
{

}

/***************************************************************
 * cpgrect -- draw a rectangle, using fill-area attributes
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgrect(float x1, float x2, float y1, float y2)
{

}

/***************************************************************
 * cpgrnd -- find the smallest `round' number greater than x
 * Status: NOT IMPLEMENTED
 ***************************************************************/
float cpgrnd(float x, int *nsub)
{

}

/***************************************************************
 * cpgrnge -- choose axis limits
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgrnge(float x1, float x2, float *xlo, float *xhi)
{

}

/***************************************************************
 * cpgsah -- set arrow-head style
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgsah(int fs, float angle, float barb)
{

}

/***************************************************************
 * cpgsave -- save pgplot attributes
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgsave(void)
{

}

/***************************************************************
 * cpgunsa -- restore pgplot attributes
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgunsa(void)
{

}

/***************************************************************
 * cpgscf -- set character font
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgscf(int font)
{

}

/***************************************************************
 * cpgsch -- set character height
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgsch(float size)
{

}

/***************************************************************
 * cpgsci -- set color index
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgsci(int ci)
{

}

/***************************************************************
 * cpgscir -- set color index range
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgscir(int icilo, int icihi)
{

}

/***************************************************************
 * cpgsclp -- enable or disable clipping at edge of viewport
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgsclp(int state)
{

}

/***************************************************************
 * cpgscr -- set color representation
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgscr(int ci, float cr, float cg, float cb)
{

}

/***************************************************************
 * cpgscrl -- scroll window
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgscrl(float dx, float dy)
{

}

/***************************************************************
 * cpgscrn -- set color representation by name
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgscrn(int ci, const char *name, int *ier)
{

}

/***************************************************************
 * cpgsfs -- set fill-area style
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgsfs(int fs)
{

}

/***************************************************************
 * cpgshls -- set color representation using hls system
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgshls(int ci, float ch, float cl, float cs)
{

}

/***************************************************************
 * cpgshs -- set hatching style
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgshs(float angle, float sepn, float phase)
{

}

/***************************************************************
 * cpgsitf -- set image transfer function
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgsitf(int itf)
{

}

/***************************************************************
 * cpgslct -- select an open graphics device
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgslct(int id)
{

}

/***************************************************************
 * cpgsls -- set line style
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgsls(int ls)
{

}

/***************************************************************
 * cpgslw -- set line width
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgslw(int lw)
{

}

/***************************************************************
 * cpgstbg -- set text background color index
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgstbg(int tbci)
{

}

/***************************************************************
 * cpgsubp -- subdivide view surface into panels
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgsubp(int nxsub, int nysub)
{

}

/***************************************************************
 * cpgsvp -- set viewport (normalized device coordinates)
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgsvp(float xleft, float xright, float ybot, float ytop)
{

}

/***************************************************************
 * cpgswin -- set window
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgswin(float x1, float x2, float y1, float y2)
{

}

/***************************************************************
 * cpgtbox -- draw frame and write (dd) hh mm ss.s labelling
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgtbox(const char *xopt, float xtick, int nxsub, \
 const char *yopt, float ytick, int nysub)
{

}

/***************************************************************
 * cpgtext -- write text (horizontal, left-justified)
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgtext(float x, float y, const char *text)
{

}

/***************************************************************
 * cpgtick -- draw a single tick mark on an axis
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgtick(float x1, float y1, float x2, float y2, float v, \
 float tikl, float tikr, float disp, float orient, const char *str)
{

}

/***************************************************************
 * cpgupdt -- update display
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgupdt(void)
{

}

/***************************************************************
 * cpgvect -- vector map of a 2D data array, with blanking
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgvect(const float *a, const float *b, int idim, int jdim, \
 int i1, int i2, int j1, int j2, float c, int nc, \
 const float *tr, float blank)
{

}

/***************************************************************
 * cpgvsiz -- set viewport (inches)
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgvsiz(float xleft, float xright, float ybot, float ytop)
{

}

/***************************************************************
 * cpgvstd -- set standard (default) viewport
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgvstd(void)
{

}

/***************************************************************
 * cpgwedg -- annotate an image plot with a wedge
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgwedg(const char *side, float disp, float width, \
 float fg, float bg, const char *label)
{

}

/***************************************************************
 * cpgwnad -- set window and adjust viewport to same aspect ratio
 * Status: NOT IMPLEMENTED
 ***************************************************************/
void cpgwnad(float x1, float x2, float y1, float y2)
{

}
