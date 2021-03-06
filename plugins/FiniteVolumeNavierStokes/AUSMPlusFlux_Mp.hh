#ifndef COOLFluiD_Numerics_FiniteVolume_AUSMPlusFlux_Mp_hh
#define COOLFluiD_Numerics_FiniteVolume_AUSMPlusFlux_Mp_hh

//////////////////////////////////////////////////////////////////////////////

#include "FiniteVolumeNavierStokes/AUSMFlux.hh"

//////////////////////////////////////////////////////////////////////////////

namespace COOLFluiD {

  namespace Numerics {

    namespace FiniteVolume {

//////////////////////////////////////////////////////////////////////////////

/**
 * This class computes the AUSM+ flux
 *
 * @author Andrea Lani
 *
 */
template <class UPDATEVAR>
class AUSMPlusFlux_Mp : public AUSMFlux<UPDATEVAR> {
public:
  
  /**
   * Constructor
   */
  AUSMPlusFlux_Mp(const std::string& name);

  /**
   * Default destructor
   */
  virtual ~AUSMPlusFlux_Mp();
  
  /**
   * Defines the Config Option's of this class
   * @param options a OptionList where to add the Option's
   */
  static void defineConfigOptions(Config::OptionList& options);
  
  /**
   * Configure the data from the supplied arguments.
   * @param args configuration arguments
   */
  virtual void configure ( Config::ConfigArgs& args )
  {
    AUSMFlux<UPDATEVAR>::configure(args);
  }

protected:
  
  virtual void computeMassFlux();		//interface mass flux
  virtual void computePressureFlux();		//interface pressure flux	
  virtual void computeIncompCorrectionTerm();   //incompressible correction term mp
  
private:
  
  CFreal m_beta;					//beta coeficient
  CFreal m_alpha;					//alpha coeficient
  CFreal m_Vinf;					// V infinite
  CFreal m_Lref;					// Reference length, shortest cell size
  CFreal m_nu;						// dynamic viscosity
  CFuint m_ChoiceLref;					// Choice of method to compute Lref
  CFuint m_ChoiceMp;					// Choice of method for computing mp
  CFreal m_uco;						// cut-off speed
  CFreal m_umax;					// higher bound speed

}; // end of class AUSMPlusFlux_Mp

//////////////////////////////////////////////////////////////////////////////

    } // namespace FiniteVolume

  } // namespace Numerics

} // namespace COOLFluiD

//////////////////////////////////////////////////////////////////////////////

#include "AUSMPlusFlux_Mp.ci"

//////////////////////////////////////////////////////////////////////////////

#endif // COOLFluiD_Numerics_FiniteVolume_AUSMPlusFlux_Mp_hh
