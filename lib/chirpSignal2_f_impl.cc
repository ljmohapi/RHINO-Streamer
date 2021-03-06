/* -*- c++ -*- */
/* 
 * Copyright 2016 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "chirpSignal2_f_impl.h"

namespace gr {
  namespace MpatiBlocks {

    chirpSignal2_f::sptr
    chirpSignal2_f::make(float f_phase,float f_freq_0,float f_freq_1,float f_time_1,bool f_repeat)
    {
      return gnuradio::get_initial_sptr
        (new chirpSignal2_f_impl(f_phase, f_freq_0, f_freq_1, f_time_1, f_repeat));
    }

    /*
     * The private constructor
     */
    chirpSignal2_f_impl::chirpSignal2_f_impl(float phase,float freq_0,float freq_1,float time_1,bool repeat = false)
      : gr::sync_block("chirpSignal2_f",
              gr::io_signature::make(0, 0, 0),
              gr::io_signature::make(1, 1, sizeof(float))),f_phase(phase),f_freq_0(freq_0),f_freq_1(freq_1),f_time_1(time_1),f_repeat(repeat)
    {}

    /*
     * Our virtual destructor.
     */
    chirpSignal2_f_impl::~chirpSignal2_f_impl() 
    {
    }

    int
    chirpSignal2_f_impl::work(int noutput_items,
			  gr_vector_const_void_star &input_items,
			  gr_vector_void_star &output_items)
    {
     float *out = (float *) output_items[0];
	 std::vector<float>  t,y;// = 0.0:0.001:5.0;
	 int L = 5000;	
	   
	 int size = noutput_items;
	float phase = 2*(M_PI*f_phase)/360.0f;
	
	float a = (M_PI *(f_freq_1-f_freq_0))/f_time_1;
	
	float b = 2*M_PI*f_freq_0;	
	t.resize(L);
	y.resize(L);
	int i=0; 
	float tindexer = 0.0f;
	while(true)//i<L)
	{
		
		t[i] = tindexer;
		tindexer = tindexer + 0.001f;
		
		out[i] = cos(a*pow(t[i],2)+(b*t[i])+phase);
		

		/*if (i==L-1) //
		{
			if(f_repeat == false)
				break; 
		
		}*/
		i +=1;
		return noutput_items;
    
   	}

   
    }
    
    bool chirpSignal2_f_impl::set_repeat(bool repeat)
    {
		f_repeat=repeat;
		return f_repeat;
	}
    
    void
    chirpSignal2_f_impl::set_phase(float phase)
    {
      f_phase = phase;
    }

    void
    chirpSignal2_f_impl::set_start_freq(float frequency)
    {
      f_freq_0= frequency;
    }

    void
    chirpSignal2_f_impl::set_freq_1(float freq)
    {
      f_freq_1=freq;

    }

    void
    chirpSignal2_f_impl::set_time(float t)
    {
      f_time_1 = t;
    }
    

  } /* namespace MpatiBlocks */
} /* namespace gr */

