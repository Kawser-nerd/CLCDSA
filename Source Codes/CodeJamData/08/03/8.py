#!/usr/bin/python

import sys, math

def getline():
    return sys.stdin.readline()[:-1]

def trace(*strs):
    return
    print >> sys.stderr, '..',
    for str in strs:
        print >> sys.stderr, str,
    print >> sys.stderr

def get_area_of_slice(R, xlo, xhi):
    # integral of sqrt(R^2 - x^2) dx
    # CRC integral #157
    assert -R <= xlo <= xhi <= R
    def thing(x):
        return x * math.sqrt(R*R - x*x) + R*R * math.asin(x/R)
    return thing(xhi) - thing(xlo)

n_cases = int(getline())
trace(n_cases,'cases:')
for case_num in range(1,n_cases+1):
    trace()
    trace( 'Case #', case_num )

    (f, R, t, r, g) = map(float,getline().split())
    trace('f:', f)
    trace('R:', R)
    trace('t:', t)
    trace('r:', r)
    trace('g:', g)

    if 2*f >= g:
        trace('fly is too fat, will always get hit (fly diam %f >= gap %f)' % (2*f, g))
        probability_of_hit = 1.0
    elif t == R:
        trace("racket is a solid 'ring', fly will always be hit")
        # but we're told that t < R
        probability_of_hit = 1.0
    elif r+t >= R:
        trace("racket is all ring+string, fly will always be hit")
        probability_of_hit = 1.0
    else:

        # The fly-center is inside the outer radius
        # and is equally likely to be anywhere within that radius. 
        total_area = math.pi * R * R

        # (could try Monte Carlo, but could be fairly time consuming
        # to get error down to 10^-6)

        # Equivalent to widening each string by f on either side,
        rw = r + f
        # (which narrows each gap by 2*f)
        gw = g - 2*f
        # and widening the outer ring by r on the inside,
        tw = t + f
        # and then swatting a point fly.
        fw = 0

        trace('now:')
        trace('  rw:', rw)
        trace('  gw:', gw)
        trace('  tw:', tw)
        trace('  fw:', fw)

        string_cc = 2 * rw + gw # center-to-center distance

        # Calculate where the widened strings hit the widened ring.
        #
        # "rim" is inner face of widened ring
        rim_radius = R - tw
        
        # We'll just sweep a half of the circle (by x) and then mult by 2.
        rim_is_in_hgap = None
        significant_ordinates = []
        for i in xrange(1,sys.maxint):
            # gap #i (1-based)
            vgap_lo_x = (i-1) * string_cc + rw
            vgap_hi_x =  i    * string_cc - rw

            trace('gap #%i: %f - %f' % (i, vgap_lo_x, vgap_hi_x))

            def foo( x, i, this_event, other_event  ):
                significant_ordinates.append( (x, i, this_event) )
                if other_event is not None:
                    y = math.sqrt( rim_radius*rim_radius - x*x )
                    significant_ordinates.append( (y, i, other_event) )


            if vgap_lo_x >= rim_radius:
                trace('   is completely beyond rim')
                foo( R, i, 'vgap_begins', None )

                rim_is_in_hgap = False
                hgap_num = i-1 # gap_num of the last gap before the rim
                break

            elif vgap_hi_x > rim_radius:
                trace('    straddles rim')
                rim_is_in_hgap = True
                hgap_num = i

                foo( vgap_lo_x,  i,   'vgap_begins', 'rim_leaves_hgap' )
                foo( rim_radius, i,   'vgap_ends',   None )
                foo( R,          i+1, 'vgap_begins', None )
                break

            else:
                foo( vgap_lo_x, i, 'vgap_begins', 'rim_leaves_hgap' )
                foo( vgap_hi_x, i, 'vgap_ends',   'rim_enters_hgap' )

        # There are a few possibilities for slices:
        # -- the slice is within a vertical string:
        #       no contribution to safe area
        # -- the slice is not within a vertical string:
        #       Usually some contribution to safe area...
        #       -- the final vertical gaps are "complete" (squared off)
        #       -- the final vertical gaps are incomplete (rounded at rim)

        significant_ordinates.sort()
        trace('sorted significant_ordinates:')
        for so in significant_ordinates:
            trace('  ', so)

        trace('sweeping...')
        total_full_area_by_slice = 0.0
        total_safe = 0.0
        total_unsafe = 0.0
        prev_x = 0.0
        x_is_in_vgap = False
        # rim_is_in_hgap set above
        # hgap_num set above
        trace('    x not in vgap')
        if rim_is_in_hgap:
            trace('    rim in hgap')
        else:
            trace('    rim not in hgap')

        for so in significant_ordinates:

            # First, calculate the contribution of the slice that is just ending.
            # So we only care about the new_x
            (new_x, _, _) = so
            trace('current slice ends at', new_x)
            area_of_full_slice = get_area_of_slice(R,prev_x,new_x)

            if x_is_in_vgap:
                if rim_is_in_hgap:
                    trace('   x in vgap #', vgap_num, ', rim in hgap')
                    # rounded gap-ends
                    # So the (hgap_num)'th hgap at each end is rounded.
                    # So there are 2*hgap_num-1 complete-height h-strings, 
                    area_of_inrim_slice = get_area_of_slice(rim_radius,prev_x,new_x)
                    string_area = (2*hgap_num-1) * (2 * rw) * (new_x - prev_x)
                    safe_portion = area_of_inrim_slice - string_area
                else:
                    trace('   x in vgap #', vgap_num, ', rim not in hgap')
                    # final hgaps are "complete" squared gap-ends
                    # So we have have (2*hgap_num) complete hgaps of height gw
                    # and some width.
                    safe_portion = 2 * hgap_num * gw * (new_x - prev_x)
            else:
                trace('    x not in vgap')
                safe_portion = 0.0

            unsafe_portion = area_of_full_slice - safe_portion
            trace('    %f full   %f safe   %f unsafe' % (
                area_of_full_slice, safe_portion, unsafe_portion) )

            total_full_area_by_slice += area_of_full_slice
            total_safe += safe_portion
            total_unsafe += unsafe_portion

            prev_x = new_x

            # ---------
            trace('   ', so)

            # Now, change state
            (_, gap_num, event) = so
            if event == 'vgap_begins':
                assert not x_is_in_vgap
                x_is_in_vgap = True
                vgap_num = gap_num
            elif event == 'vgap_ends':
                assert x_is_in_vgap
                x_is_in_vgap = False
                vgap_num = None
            elif event == 'rim_enters_hgap':
                assert not rim_is_in_hgap
                rim_is_in_hgap = True
                assert gap_num == hgap_num
            elif event == 'rim_leaves_hgap':
                assert rim_is_in_hgap
                rim_is_in_hgap = False
                assert gap_num == hgap_num
                hgap_num = gap_num-1
            else:
                assert 0

        trace('%f total_full_area_by_slice' % total_full_area_by_slice )
        trace('%f total_safe' % total_safe )
        trace('%f total_unsafe' % total_unsafe )

        # don't forget to multiply by 2!!
        total_full_area_by_slice *= 2
        total_safe *= 2
        total_unsafe *= 2

        def assert_near_equal( a, b ):
            trace(a,b)
            assert abs(a - b) <= 1e-6, (a,b) 
            assert abs(a - b) / ((a+b)/2) <= 1e-6, (a,b)

        assert_near_equal( total_safe + total_unsafe, total_full_area_by_slice )
        assert_near_equal( total_full_area_by_slice, total_area )

        probability_of_hit = total_unsafe / total_area

    print 'Case #%d: %f' % (case_num, probability_of_hit)

assert sys.stdin.readline() == ''

# vim: sw=4 ts=4 expandtab
