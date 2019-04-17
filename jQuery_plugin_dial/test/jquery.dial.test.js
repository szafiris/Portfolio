describe('Dial jQuery plugin', () => {
  const options = {
    change: () => {
      // No-op; Jasmine spy will check on whether this got called.
    }
  }

  beforeEach(() => {
    fixture.setBase('test')
    fixture.load('jquery.dial.fixture.html')
  })

  afterEach(() => fixture.cleanup())

  it('should return itself when the plugin is installed', () => {
    const $target = $('.dial-test')
    const $pluginResult = $target.dial(options)

    expect($pluginResult).toBe($target)
  })

  let transformUpdateTest = () => {
    const mousedown = $.Event('mousedown', { screenX: 20 })
    $('.dial-test').trigger(mousedown)

    let mousemove = $.Event('mousemove', { screenX: 10 })
    $('.dial-test').trigger(mousemove)
    expect($('.dial-test').attr('style')).toBe('transform: perspective(500px) rotateZ(-10deg);')

    mousemove = $.Event('mousemove', { screenX: 30 })
    $('.dial-test').trigger(mousemove)
    expect($('.dial-test').attr('style')).toBe('transform: perspective(500px) rotateZ(10deg);')

    $('.dial-test').trigger($.Event('mouseup'))
  }

  let dialAngleUpdateTest = () => {
    const mousedown = $.Event('mousedown', { screenX: 20 })
    $('.dial-test').trigger(mousedown)

    let mousemove = $.Event('mousemove', { screenX: 10 })
    $('.dial-test').trigger(mousemove)
    expect($('.dial-test').data('dial-angle')).toBe(-10)

    mousemove = $.Event('mousemove', { screenX: 30 })
    $('.dial-test').trigger(mousemove)
    expect($('.dial-test').data('dial-angle')).toBe(10)

    mousemove = $.Event('mousemove', { screenX: 150 })
    $('.dial-test').trigger(mousemove)
    expect($('.dial-test').data('dial-angle')).toBe(90)

    mousemove = $.Event('mousemove', { screenX: -150 })
    $('.dial-test').trigger(mousemove)
    expect($('.dial-test').data('dial-angle')).toBe(-90)

    $('.dial-test').trigger($.Event('mouseup'))
  }

  describe('installed behavior with callback', () => {
    beforeEach(() => $('.dial-test').dial(options))

    it('should update its CSS transform correctly', transformUpdateTest)
    it('should update the dial angle correctly', dialAngleUpdateTest)

    it('should invoke the callback correctly', () => {
      spyOn(options, 'change')

      const mousedown = $.Event('mousedown', { screenX: 20 })
      $('.dial-test').trigger(mousedown)

      let mousemove = $.Event('mousemove', { screenX: 10 })
      $('.dial-test').trigger(mousemove)
      expect(options.change).toHaveBeenCalledWith(0, -10)

      mousemove = $.Event('mousemove', { screenX: 30 })
      $('.dial-test').trigger(mousemove)
      expect(options.change).toHaveBeenCalledWith(-10, 10)

      $('.dial-test').trigger($.Event('mouseup'))
    })
  })

  describe('installed behavior without callback', () => {
    beforeEach(() => $('.dial-test').dial())

    it('should update its CSS transform correctly', transformUpdateTest)
    it('should update the dial angle correctly', dialAngleUpdateTest)
  })
})
