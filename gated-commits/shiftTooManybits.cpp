static inline int blake2b_increment_counter( blake2b_state *S, const uint64_t inc )
{
#ifdef HAVE_TI_MODE
  uint128_t t = ( ( uint128_t )S->t[1] << 64 ) | S->t[0];
  t += inc;
  S->t[0] = ( uint64_t )( t >>  0 );
  S->t[1] = ( uint64_t )( t >> 64 );
#else
  S->t[0] += inc;
  S->t[1] += ( S->t[0] < inc );
#endif
  return 0;
}